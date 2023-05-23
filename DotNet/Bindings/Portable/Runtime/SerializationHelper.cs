using System;
using System.IO;
using Urho.Json;

namespace Urho
{
    public static class SerializationHelper
    {

        public static object DeserializeJson(this Type type, string toDeserialize)
        {
            try
            {
                return JsonConvert.DeserializeObject(toDeserialize, type);
            }
            catch
            {
                return null;
            }
        }

        public static string SerializeJson(this Type toSerialize)
        {
            try
            {
                return JsonConvert.SerializeObject(toSerialize);
            }
            catch
            {
                return string.Empty;
            }
        }

        public static T DeserializeJson<T>(this string toDeserialize)
        {
            return JsonConvert.DeserializeObject<T>(toDeserialize);
        }

        public static string SerializeJson<T>(this T toSerialize)
        {
            return JsonConvert.SerializeObject(toSerialize);
        }
    }
}