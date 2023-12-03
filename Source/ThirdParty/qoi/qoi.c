#define QOI_IMPLEMENTATION
#include "qoi.h"

union endian_check_union_t
{
    int i;
    char c[sizeof(int)];
};

int is_little_endian()
{
    union endian_check_union_t check;
    check.i = 1;
    if (check.c[0] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int qoi_encode_ext(const unsigned char* data, const qoi_desc desc, unsigned char* out_bytes)
{
    int i, p, run;
    int px_len, px_end, px_pos, channels;
    unsigned char* bytes = out_bytes;
    const unsigned char* pixels;
    qoi_rgba_t index[64];
    qoi_rgba_t px, px_prev;

    if (data == NULL || desc.width == 0 || desc.height == 0 || desc.channels < 3 || desc.channels > 4 ||
        desc.colorspace > 1 || desc.height >= QOI_PIXELS_MAX / desc.width)
    {
        return -1;
    }

    p = 0;

    qoi_write_32(bytes, &p, QOI_MAGIC);
    qoi_write_32(bytes, &p, desc.width);
    qoi_write_32(bytes, &p, desc.height);
    bytes[p++] = desc.channels;
    bytes[p++] = desc.colorspace;

    pixels = (const unsigned char*)data;

    QOI_ZEROARR(index);

    run = 0;
    px_prev.rgba.r = 0;
    px_prev.rgba.g = 0;
    px_prev.rgba.b = 0;
    px_prev.rgba.a = 255;
    px = px_prev;

    px_len = desc.width * desc.height * desc.channels;
    px_end = px_len - desc.channels;
    channels = desc.channels;

    for (px_pos = 0; px_pos < px_len; px_pos += channels)
    {
        px.rgba.r = pixels[px_pos + 0];
        px.rgba.g = pixels[px_pos + 1];
        px.rgba.b = pixels[px_pos + 2];

        if (channels == 4)
        {
            px.rgba.a = pixels[px_pos + 3];
        }

        if (px.v == px_prev.v)
        {
            run++;
            if (run == 62 || px_pos == px_end)
            {
                bytes[p++] = QOI_OP_RUN | (run - 1);
                run = 0;
            }
        }
        else
        {
            int index_pos;

            if (run > 0)
            {
                bytes[p++] = QOI_OP_RUN | (run - 1);
                run = 0;
            }

            index_pos = QOI_COLOR_HASH(px) % 64;

            if (index[index_pos].v == px.v)
            {
                bytes[p++] = QOI_OP_INDEX | index_pos;
            }
            else
            {
                index[index_pos] = px;

                if (px.rgba.a == px_prev.rgba.a)
                {
                    signed char vr = px.rgba.r - px_prev.rgba.r;
                    signed char vg = px.rgba.g - px_prev.rgba.g;
                    signed char vb = px.rgba.b - px_prev.rgba.b;

                    signed char vg_r = vr - vg;
                    signed char vg_b = vb - vg;

                    if (vr > -3 && vr < 2 && vg > -3 && vg < 2 && vb > -3 && vb < 2)
                    {
                        bytes[p++] = QOI_OP_DIFF | (vr + 2) << 4 | (vg + 2) << 2 | (vb + 2);
                    }
                    else if (vg_r > -9 && vg_r < 8 && vg > -33 && vg < 32 && vg_b > -9 && vg_b < 8)
                    {
                        bytes[p++] = QOI_OP_LUMA | (vg + 32);
                        bytes[p++] = (vg_r + 8) << 4 | (vg_b + 8);
                    }
                    else
                    {
                        bytes[p++] = QOI_OP_RGB;
                        bytes[p++] = px.rgba.r;
                        bytes[p++] = px.rgba.g;
                        bytes[p++] = px.rgba.b;
                    }
                }
                else
                {
                    bytes[p++] = QOI_OP_RGBA;
                    bytes[p++] = px.rgba.r;
                    bytes[p++] = px.rgba.g;
                    bytes[p++] = px.rgba.b;
                    bytes[p++] = px.rgba.a;
                }
            }
        }
        px_prev = px;
    }

    for (i = 0; i < (int)sizeof(qoi_padding); i++)
    {
        bytes[p++] = qoi_padding[i];
    }
    return p;
}

int qoi_decode_ext(const unsigned char* data, int size, qoi_desc* desc, unsigned char* pixels)
{
    const unsigned char* bytes;
    unsigned int header_magic;
    qoi_rgba_t index[64] = {0};
    qoi_rgba_t px;
    int px_len, chunks_len, px_pos;
    int p = 0, run = 0, channels = 0;

    if (data == NULL || desc == NULL || size < QOI_HEADER_SIZE + (int)sizeof(qoi_padding))
    {
        return -1;
    }

    bytes = (const unsigned char*)data;

    header_magic = qoi_read_32(bytes, &p);
    desc->width = qoi_read_32(bytes, &p);
    desc->height = qoi_read_32(bytes, &p);
    desc->channels = bytes[p++];
    desc->colorspace = bytes[p++];
    channels = desc->channels;

    if (desc->width == 0 || desc->height == 0 || desc->channels < 3 || desc->channels > 4 || desc->colorspace > 1 ||
        header_magic != QOI_MAGIC || desc->height >= QOI_PIXELS_MAX / desc->width)
    {
        return -1;
    }

    if (channels == 0)
    {
        channels = desc->channels;
    }

    px_len = desc->width * desc->height * channels;

    QOI_ZEROARR(index);
    px.rgba.r = 0;
    px.rgba.g = 0;
    px.rgba.b = 0;
    px.rgba.a = 255;

    chunks_len = size - (int)sizeof(qoi_padding);
    for (px_pos = 0; px_pos < px_len; px_pos += channels)
    {
        if (run > 0)
        {
            run--;
        }
        else if (p < chunks_len)
        {
            int b1 = bytes[p++];

            if (b1 == QOI_OP_RGB)
            {
                px.rgba.r = bytes[p++];
                px.rgba.g = bytes[p++];
                px.rgba.b = bytes[p++];
            }
            else if (b1 == QOI_OP_RGBA)
            {
                px.rgba.r = bytes[p++];
                px.rgba.g = bytes[p++];
                px.rgba.b = bytes[p++];
                px.rgba.a = bytes[p++];
            }
            else if ((b1 & QOI_MASK_2) == QOI_OP_INDEX)
            {
                px = index[b1];
            }
            else if ((b1 & QOI_MASK_2) == QOI_OP_DIFF)
            {
                px.rgba.r += ((b1 >> 4) & 0x03) - 2;
                px.rgba.g += ((b1 >> 2) & 0x03) - 2;
                px.rgba.b += (b1 & 0x03) - 2;
            }
            else if ((b1 & QOI_MASK_2) == QOI_OP_LUMA)
            {
                int b2 = bytes[p++];
                int vg = (b1 & 0x3f) - 32;
                px.rgba.r += vg - 8 + ((b2 >> 4) & 0x0f);
                px.rgba.g += vg;
                px.rgba.b += vg - 8 + (b2 & 0x0f);
            }
            else if ((b1 & QOI_MASK_2) == QOI_OP_RUN)
            {
                run = (b1 & 0x3f);
            }

            index[QOI_COLOR_HASH(px) % 64] = px;
        }

        pixels[px_pos + 0] = px.rgba.r;
        pixels[px_pos + 1] = px.rgba.g;
        pixels[px_pos + 2] = px.rgba.b;

        if (channels == 4)
        {
            pixels[px_pos + 3] = px.rgba.a;
        }
    }

    return 0;
}

int qoi_can_encode(int width, int height, int alpha)
{
    return width > 0 && height > 0 && height <= 2147483625 / width / (alpha != 0 ? 5 : 4);
}

int qoi_encode_int_ext(int width, int height, int* pixels, int alpha, int linearColorspace, unsigned char* encoded)
{
    if (!qoi_can_encode(width, height, alpha))
        return -1;

    int isLittleEndian = is_little_endian();

    int pixelsSize = width * height;
    encoded[0] = (unsigned char)'q';
    encoded[1] = (unsigned char)'o';
    encoded[2] = (unsigned char)'i';
    encoded[3] = (unsigned char)'f';
    encoded[4] = (unsigned char)(width >> 24);
    encoded[5] = (unsigned char)(width >> 16);
    encoded[6] = (unsigned char)(width >> 8);
    encoded[7] = (unsigned char)width;
    encoded[8] = (unsigned char)(height >> 24);
    encoded[9] = (unsigned char)(height >> 16);
    encoded[10] = (unsigned char)(height >> 8);
    encoded[11] = (unsigned char)height;
    encoded[12] = (unsigned char)(alpha ? 4 : 3);
    encoded[13] = (unsigned char)(linearColorspace ? 1 : 0);

    int index[64] = {0};

    int encodedOffset = 14;
    int lastPixel = -16777216;
    int run = 0;
    for (int pixelsOffset = 0; pixelsOffset < pixelsSize;)
    {
        int pixel = pixels[pixelsOffset++];

        // if Big endian , swap byte order
        if (!isLittleEndian)
        {
            // Swap byte order
            int byte0 = (pixel >> 24) & 0xFF;
            int byte1 = (pixel >> 16) & 0xFF;
            int byte2 = (pixel >> 8) & 0xFF;
            int byte3 = pixel & 0xFF;

            pixel = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | byte0;
        }

        if (!alpha)
            pixel |= -16777216;
        if (pixel == lastPixel)
        {
            if (++run == 62 || pixelsOffset >= pixelsSize)
            {
                encoded[encodedOffset++] = (unsigned char)(191 + run);
                run = 0;
            }
        }
        else
        {
            if (run > 0)
            {
                encoded[encodedOffset++] = (unsigned char)(191 + run);
                run = 0;
            }
            int indexOffset = ((pixel >> 16) * 3 + (pixel >> 8) * 5 + (pixel & 63) * 7 + (pixel >> 24) * 11) & 63;
            if (pixel == index[indexOffset])
                encoded[encodedOffset++] = (unsigned char)indexOffset;
            else
            {
                index[indexOffset] = pixel;
                int a = pixel >> 24 & 255;
                int r = pixel >> 16 & 255;
                int g = pixel >> 8 & 255;
                int b = pixel & 255;

                if ((pixel ^ lastPixel) >> 24 != 0)
                {
                    encoded[encodedOffset] = 255;
                    encoded[encodedOffset + 1] = (unsigned char)r;
                    encoded[encodedOffset + 2] = (unsigned char)g;
                    encoded[encodedOffset + 3] = (unsigned char)b;
                    encoded[encodedOffset + 4] = (unsigned char)a;
                    encodedOffset += 5;
                }
                else
                {
                    int dr = r - (lastPixel >> 16 & 255);
                    int dg = g - (lastPixel >> 8 & 255);
                    int db = b - (lastPixel & 255);
                    if (dr >= -2 && dr <= 1 && dg >= -2 && dg <= 1 && db >= -2 && db <= 1)
                        encoded[encodedOffset++] = (unsigned char)(106 + (dr << 4) + (dg << 2) + db);
                    else
                    {
                        dr -= dg;
                        db -= dg;
                        if (dr >= -8 && dr <= 7 && dg >= -32 && dg <= 31 && db >= -8 && db <= 7)
                        {
                            encoded[encodedOffset] = (unsigned char)(160 + dg);
                            encoded[encodedOffset + 1] = (unsigned char)(136 + (dr << 4) + db);
                            encodedOffset += 2;
                        }
                        else
                        {
                            encoded[encodedOffset] = 254;
                            encoded[encodedOffset + 1] = (unsigned char)r;
                            encoded[encodedOffset + 2] = (unsigned char)g;
                            encoded[encodedOffset + 3] = (unsigned char)b;
                            encodedOffset += 4;
                        }
                    }
                }
            }
            lastPixel = pixel;
        }
    }
    memset(&encoded[encodedOffset], 0, 7 * sizeof(unsigned char));
    encoded[encodedOffset + 7] = 1;
    return encodedOffset + 8;
}

int qoi_decode_int_ext(unsigned char* encoded, int encodedSize, int* out_data, int* Width, int* Height, int* Alpha,int* LinearColorspace)
{
    *Alpha = 0;
    *LinearColorspace = 0;
    *Width = 0;
    *Height = 0;
    if (encodedSize < 23 || encoded[0] != 'q' || encoded[1] != 'o' || encoded[2] != 'i' || encoded[3] != 'f')
        return -1;
    int width = encoded[4] << 24 | encoded[5] << 16 | encoded[6] << 8 | encoded[7];
    int height = encoded[8] << 24 | encoded[9] << 16 | encoded[10] << 8 | encoded[11];
    if (width <= 0 || height <= 0 || height > 2147483647 / width)
        return -1;
    switch (encoded[12])
    {
    case 3:
        *Alpha = 0;
        break;
    case 4:
        *Alpha = 1;
        break;
    default:
        return -1;
    }
    switch (encoded[13])
    {
    case 0:
        *LinearColorspace = 0;
        break;
    case 1:
        *LinearColorspace = 1;
        break;
    default:
        return -1;
    }
    int pixelsSize = width * height;
    encodedSize -= 8;
    int encodedOffset = 14;
    int index[64] = {0};
    int pixel = -16777216;
    for (int pixelsOffset = 0; pixelsOffset < pixelsSize;)
    {
        if (encodedOffset >= encodedSize)
            return -1;
        int e = encoded[encodedOffset++];
        switch (e >> 6)
        {
        case 0:
        {
            out_data[pixelsOffset++] = pixel = index[e];
        }
            continue;
        case 1:
        {
            pixel = (pixel & -16777216) | ((pixel + (((e >> 4) - 4 - 2) << 16)) & 16711680) |
                    ((pixel + (((e >> 2 & 3) - 2) << 8)) & 65280) | ((pixel + (e & 3) - 2) & 255);
        }
        break;
        case 2:
        {
            e -= 160;
            int rb = encoded[encodedOffset++];
            pixel = (pixel & -16777216) | ((pixel + ((e + (rb >> 4) - 8) << 16)) & 16711680) |
                    ((pixel + (e << 8)) & 65280) | ((pixel + e + (rb & 15) - 8) & 255);
        }
        break;
        default:
        {
            if (e < 254)
            {
                e -= 191;
                if (pixelsOffset + e > pixelsSize)
                    return -1;
                for (int i = 0; i < e; ++i)
                    out_data[pixelsOffset++] = pixel;
                continue;
            }
            if (e == 254)
            {
                pixel = (pixel & -16777216) | encoded[encodedOffset] << 16 | encoded[encodedOffset + 1] << 8 |
                        encoded[encodedOffset + 2];
                encodedOffset += 3;
            }
            else
            {
                pixel = encoded[encodedOffset + 3] << 24 | encoded[encodedOffset] << 16 |
                        encoded[encodedOffset + 1] << 8 | encoded[encodedOffset + 2];
                encodedOffset += 4;
            }
        }
        break;
        }
        out_data[pixelsOffset++] =
            index[((pixel >> 16) * 3 + (pixel >> 8) * 5 + (pixel & 63) * 7 + (pixel >> 24) * 11) & 63] = pixel;
    }
    if (encodedOffset != encodedSize)
        return -1;
    *Width = width;
    *Height = height;
    return 0;
}