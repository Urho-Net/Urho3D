using System;
using System.IO;
using Urho.Json;
using Urho.IO;
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
            catch (Exception ex)
            {
                // Handle the exception as needed
                Log.Error($"Error deserializing JSON: {ex.Message}");
                return null;
            }
        }

        public static string SerializeJson(this Type toSerialize)
        {
            try
            {
                return JsonConvert.SerializeObject(toSerialize);
            }
            catch (Exception ex)
            {
                // Handle the exception as needed
                Log.Error($"Error serializing to JSON: {ex.Message}");
                return string.Empty;
            }
        }

        public static T DeserializeJson<T>(this string toDeserialize)
        {
            try
            {
                // For AOT platforms, add explicit type info
                var result = JsonConvert.DeserializeObject<T>(toDeserialize);
                if (result == null)
                {
                    Log.Warn($"JSON deserialization returned null for type {typeof(T).FullName}");
                }
                return result;
            }
            catch (Exception ex)
            {
                Log.Error($"Error deserializing JSON: {ex.Message}");
                if (ex.Message.Contains("missing native code or metadata"))
                {
                    Log.Error($"This is likely an AOT/trimming issue. Make sure {typeof(T).FullName} is preserved in ILLink.Descriptors.xml");
                }
                return default;
            }
        }

        public static string SerializeJson<T>(this T toSerialize)
        {
            try
            {
                return JsonConvert.SerializeObject(toSerialize);
            }
            catch (Exception ex)
            {
                // Handle the exception as needed
                Log.Error($"Error serializing to JSON: {ex.Message}");
                return string.Empty;
            }
        }
    }
}