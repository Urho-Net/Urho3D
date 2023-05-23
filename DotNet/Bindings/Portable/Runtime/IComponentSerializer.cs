using System;

namespace Urho.Resources
{
	public interface IComponentSerializer
	{
		void Serialize(string key, object value);
		void SetObjectValueToXmlElement(string key, object value);
	}

	public interface IComponentDeserializer
	{
		T Deserialize<T>(string key);
		object GetObjectValueFromXmlElement(Type type, string key);
	}

	/// <summary>
	/// XMLElement based implementation of IComponentSerializer
	/// </summary>
	public class XmlComponentSerializer : IComponentSerializer, IComponentDeserializer
	{
		public readonly XmlElement xmlElement;

		public XmlComponentSerializer(XmlElement xmlElement)
		{
			this.xmlElement = xmlElement;
		}

		public void Serialize(string key, object value)
		{
			if (value == null)
				return;

			if (value is string)
				xmlElement.SetString(key, (string)value);
			else if (value is Vector2)
				xmlElement.SetVector2(key, (Vector2)value);
			else if (value is Vector3)
				xmlElement.SetVector3(key, (Vector3)value);
			else if (value is Vector4)
				xmlElement.SetVector4(key, (Vector4)value);
			else if (value is IntRect)
				xmlElement.SetIntRect(key, (IntRect)value);
			else if (value is Quaternion)
				xmlElement.SetQuaternion(key, (Quaternion)value);
			else if (value is Color)
				xmlElement.SetColor(key, (Color)value);
			else if (value is float)
				xmlElement.SetFloat(key, (float)value);
			else if (value is int)
				xmlElement.SetInt(key, (int)value);
			else if (value is uint)
				xmlElement.SetUInt(key, (uint)value);
			else if (value is bool)
				xmlElement.SetBool(key, (bool)value);
			else if (value is double)
				xmlElement.SetDouble(key, (double)value);
            else if (value.GetType().IsEnum)
                xmlElement.SetAttribute(key, value.ToString());

			else throw new NotSupportedException($"{value.GetType().Name} is not supported."); 
		}

		public T Deserialize<T>(string key)
		{
			var type = typeof (T);
			if (type == typeof (string))
				return (T)(object) xmlElement.GetAttribute(key);
			else if (type == typeof (Vector2))
				return (T) (object) xmlElement.GetVector2(key);
			else if (type == typeof (Vector3))
				return (T) (object) xmlElement.GetVector3(key);
			else if (type == typeof (Vector4))
				return (T) (object) xmlElement.GetVector4(key);
			else if (type == typeof (Quaternion))
				return (T) (object) xmlElement.GetQuaternion(key);
			else if (type == typeof (Color))
				return (T) (object) xmlElement.GetColor(key);
			else if (type == typeof (float))
				return (T) (object) xmlElement.GetFloat(key);
			else if (type == typeof (double))
				return (T) (object) xmlElement.GetDouble(key);
			else if (type == typeof (int))
				return (T) (object) xmlElement.GetInt(key);
			else if (type == typeof (uint))
				return (T) (object) xmlElement.GetUInt(key);
			else if (type == typeof (bool))
				return (T) (object) xmlElement.GetBool(key);
            else if (type.IsEnum)
            {
                if (Enum.TryParse(type, xmlElement.GetAttribute(key), out object result))
                {
                    return (T)result;
                }
                else
                {
                    System.Array enumValues = type.GetEnumValues();
                    if (enumValues.Length > 0)
                        return (T)enumValues.GetValue(0);
                    else
                        return (T)(object)0;
                }
            }

			else throw new NotSupportedException($"{type.Name} is not supported."); 
		}

		public object GetObjectValueFromXmlElement(Type type, string key)
        {
            if (type == typeof(string))
                return xmlElement.GetAttribute(key);
            else if (type == typeof(Vector2))
                return (object)xmlElement.GetVector2(key);
            else if (type == typeof(BoundingBox))
                return (object)xmlElement.GetBoundingBox(key);
            else if (type == typeof(Vector3))
                return (object)xmlElement.GetVector3(key);
            else if (type == typeof(Vector4))
                return (object)xmlElement.GetVector4(key);
            else if (type == typeof(IntRect))
                return (object)xmlElement.GetIntRect(key);
            else if (type == typeof(Quaternion))
                return (object)xmlElement.GetQuaternion(key);
            else if (type == typeof(Color))
                return (object)xmlElement.GetColor(key);
            else if (type == typeof(float))
                return (object)xmlElement.GetFloat(key);
            else if (type == typeof(int))
                return (object)xmlElement.GetInt(key);
            else if (type == typeof(uint))
                return (object)xmlElement.GetUInt(key);
            else if (type == typeof(bool))
                return (object)xmlElement.GetBool(key);
            else if (type == typeof(double))
                return (object)xmlElement.GetDouble(key);
            else if (type == typeof(long))
                return (object)xmlElement.GetInt64(key);
            else if (type == typeof(IntVector2))
                return (object)xmlElement.GetIntVector2(key);
            else if (type == typeof(Matrix3))
                return (object)xmlElement.GetMatrix3(key);
            else if (type == typeof(Matrix3x4))
                return (object)xmlElement.GetMatrix3x4(key);
            else if (type == typeof(Matrix4))
                return (object)xmlElement.GetMatrix4(key);
            else if (type == typeof(ulong))
                return (object)xmlElement.GetUInt64(key);
            else if (type.IsEnum)
            {
                if (Enum.TryParse(type, xmlElement.GetAttribute(key), out object result))
                {
                    return result;
                }
                else
                {
                    System.Array enumValues = type.GetEnumValues();
                    if (enumValues.Length > 0)
                        return enumValues.GetValue(0);
                    else
                        return (object)0;
                }
            }
            else
            {
                // use Json deserialization
                string attr = xmlElement.GetAttribute(key);
                if (attr != string.Empty)
                {
                    try
                    {
                        return type.DeserializeJson(attr);
                    }
                    catch
                    {
                        return null;
                    }
                }
            }

            return null;
        }

		public void SetObjectValueToXmlElement(string key, object value)
        {
            if (value == null)
                return;

            if (value is string)
                xmlElement.SetAttribute(key, (string)value);
            else if (value is Vector2)
                xmlElement.SetVector2(key, (Vector2)value);
            else if (value is BoundingBox)
                xmlElement.SetBoundingBox(key, (BoundingBox)value);
            else if (value is Vector3)
                xmlElement.SetVector3(key, (Vector3)value);
            else if (value is Vector4)
                xmlElement.SetVector4(key, (Vector4)value);
            else if (value is IntRect)
                xmlElement.SetIntRect(key, (IntRect)value);
            else if (value is Quaternion)
                xmlElement.SetQuaternion(key, (Quaternion)value);
            else if (value is Color)
                xmlElement.SetColor(key, (Color)value);
            else if (value is float)
                xmlElement.SetFloat(key, (float)value);
            else if (value is int)
                xmlElement.SetInt(key, (int)value);
            else if (value is uint)
                xmlElement.SetUInt(key, (uint)value);
            else if (value is bool)
                xmlElement.SetBool(key, (bool)value);
            else if (value is double)
                xmlElement.SetDouble(key, (double)value);
            else if (value is long)
                xmlElement.SetInt64(key, (long)value);
            else if (value is IntVector2)
                xmlElement.SetIntVector2(key, (IntVector2)value);
            else if (value is Matrix3)
                xmlElement.SetMatrix3(key, (Matrix3)value);
            else if (value is Matrix3x4)
                xmlElement.SetMatrix3x4(key, (Matrix3x4)value);
            else if (value is Matrix4)
                xmlElement.SetMatrix4(key, (Matrix4)value);
            else if (value is ulong)
                xmlElement.SetUInt64(key, (ulong)value);
            else if (value.GetType().IsEnum)
                xmlElement.SetAttribute(key, value.ToString());
            else
            {
                 // use Json Serialization
                try
                {
                    xmlElement.SetAttribute(key, value.SerializeJson());
                }
                catch (Exception exc)
                {
                    // throw new InvalidOperationException($"SerializeJson of {value.GetType()} failed.", exc);
                }
            }
        
        }

	}

	//TODO: binary serializer
}
