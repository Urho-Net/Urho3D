

using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using Urho.Urho2D;
using Urho.Gui;
using Urho.Resources;
using Urho.IO;
using Urho.Navigation;
using Urho.Network;

namespace Urho
{
    public class DynamicMap : EventDataContainer
    {
        Dictionary<int, Dynamic> dynamicMap ;

        public DynamicMap():base()
        {
            dynamicMap = new Dictionary<int, Dynamic>();
        }

        public DynamicMap(IntPtr handle):base(handle)
        {
            dynamicMap = new Dictionary<int, Dynamic>();
        }
        public  DynamicMap(EventDataContainer eventDataContainer):base(eventDataContainer.Handle)
        {

        }

        public bool Contains(string key)
        {
            return urho_map_contains_value(Handle, StringHash.urho_stringhash_from_string (key));
        }

        public Dynamic this[String key]
    	{
			get
			{
                Dynamic dyn;
                int hash = StringHash.urho_stringhash_from_string (key);
                if (dynamicMap.TryGetValue(hash, out dyn))
                {
                    return dyn;
                }
                else
                {
                    Variant value;
                    urho_map_get_value(Handle, hash, out value);
                    dyn =  new Dynamic(value);
                    dynamicMap[hash] = dyn;
                    return dyn;
                }
			}
			
			set
			{
				int hash = StringHash.urho_stringhash_from_string (key);
                if(value.Handle != IntPtr.Zero)
                {
				    urho_map_set_value_ptr(Handle, hash ,value.Handle);
                }
                else
                {
                    Variant v = value.variant;
                    urho_map_set_value(Handle, hash ,ref v);
                }

                dynamicMap[hash] = value;
			}
            
    	}

        public bool Contains(StringHash key)
        {
            return urho_map_contains_value(Handle, key.Code);
        }

        public Dynamic this[StringHash key]
    	{
			get
			{
                Dynamic dyn;
                int hash = key.Code;
                if (dynamicMap.TryGetValue(hash, out dyn))
                {
                    return dyn;
                }
                else
                {
                    Variant value;
                    urho_map_get_value(Handle, hash, out value);
                    dyn =  new Dynamic(value);
                    dynamicMap[hash] = dyn;
                    return dyn;
                }
			}
			
			set
			{
				int hash = key.Code;
				if(value.Handle != IntPtr.Zero)
                {
				    urho_map_set_value_ptr(Handle, hash ,value.Handle);
                }
                else{
                    Variant v = value.variant;
                    urho_map_set_value(Handle, hash ,ref v);
                }

                dynamicMap[hash] = value;
			}
            
    	}

        ~DynamicMap()
		{
            dynamicMap.Clear();
			Dispose();
		}

    }

}