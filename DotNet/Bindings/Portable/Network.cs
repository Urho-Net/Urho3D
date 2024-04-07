using System;
using System.Runtime.InteropServices;

namespace Urho.Network {
	public unsafe partial class Network {

		static Connection[] ZeroArray = new Connection[0];

		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		extern static int Network_Connect (IntPtr handle, string address, short port, IntPtr scene);


		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		internal extern static IntPtr Network_GetClientConnections(IntPtr network, out int count);

		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		internal extern static IntPtr Network_GetInterfaceBroadcastAddress(string  InterfaceName);

		public Connection[] GetClientConnections () 
		{

			int count;
			IntPtr ptr = Network_GetClientConnections (handle, out count);
			if (ptr == IntPtr.Zero)
				return ZeroArray;
			
			var res = new Connection[count];
			for (int i = 0; i < count; i++){
				var connection = Marshal.ReadIntPtr(ptr, i * IntPtr.Size);
				res [i] = Runtime.LookupObject<Connection> (connection);
			}

			Utils.VoidPtr_Free(ptr);

			return res;
		}


		public bool Connect (string address, short port, Scene scene)
		{
#if __WEB__
			return false;
#else
			Runtime.ValidateRefCounted(this);
			if (address == null)
				throw new ArgumentNullException ("address");
			return Network_Connect (handle, address, port, scene?.Handle ?? IntPtr.Zero) != 0;
#endif
		}

		public void Broadcast (int msgID, bool reliable, bool inOrder, byte[] data, uint contentID = 0)
		{
			fixed (byte* bptr = data)
			{
				 BroadcastMessage(msgID,reliable,inOrder,bptr,(uint)(data.Length),contentID);
			}
		}

        public string GetBroadcastAddress(string interfaceName)
        {
            IntPtr nativeString = Network_GetInterfaceBroadcastAddress(interfaceName);
            string result = Marshal.PtrToStringAnsi(nativeString);
            return result;
        }
	}
	
}
