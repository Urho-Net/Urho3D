#include "../Resource/ResourceCache.h"
#include "../IO/File.h"
#include "../Core/Object.h"
#define PL_MPEG_IMPLEMENTATION
#define USE_URHO_FILE
#include "pl_mpeg.h"

using namespace Urho3D;

DllExport plm_t *plm_create_with_urho_file(File *fh);
DllExport plm_buffer_t *plm_buffer_create_with_urho_file(File *fh);

plm_t *plm_create_with_urho_file(File *fh) {
	plm_buffer_t *buffer = plm_buffer_create_with_file(fh, TRUE);
	if (!buffer) {
		return NULL;
	}
	return plm_create_with_buffer(buffer, TRUE);
}

plm_buffer_t *plm_buffer_create_with_urho_file(File *fh) {
	return plm_buffer_create_with_file(fh, TRUE);
}

