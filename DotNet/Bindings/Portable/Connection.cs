using System;
using System.Runtime.InteropServices;

namespace Urho.Network {
	public partial class Connection  : UrhoObject {
		public void SendMessage (int msgId, bool reliable, bool inOrder, byte [] buffer, uint contentId = 0)
		{
			Runtime.ValidateRefCounted(this);
			unsafe {
				fixed (byte *p = &buffer[0])
					Connection_SendMessage (handle, msgId, reliable, inOrder, p, (uint) buffer.Length, contentId);
			}
		}

		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		extern static IntPtr Connection_GetControls (IntPtr handle);

		[DllImport (Consts.NativeImport, CallingConvention=CallingConvention.Cdecl)]
		extern static IntPtr Connection_SetControls (IntPtr handle, IntPtr controlHandle);
		
		public Controls Controls {
			get
			{
				Runtime.ValidateRefCounted(this);
				return new Controls (this, Connection_GetControls (handle));
			}
			set
			{
				Runtime.ValidateRefCounted(this);
				Connection_SetControls (handle, value.handle);
			}
		}

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Connection_SendRemoteEvent(IntPtr handle,int eventType, bool inOrder, IntPtr eventData);

		[DllImport (Consts.NativeImport, CallingConvention = CallingConvention.Cdecl)]
		internal static extern void Connection_SendRemoteEvent2(IntPtr handle,IntPtr node ,int eventType, bool inOrder, IntPtr eventData);

		public void SendRemoteEvent(string eventType, bool inOrder, DynamicMap eventData)
		{
			SendRemoteEvent(new StringHash(eventType), inOrder, eventData);
		}

		public void SendRemoteEvent(StringHash eventType, bool inOrder, DynamicMap eventData)
		{
			Connection_SendRemoteEvent(handle,eventType.Code,inOrder,eventData.Handle);
		}

		public void SendRemoteEvent(Node node ,string eventType, bool inOrder, DynamicMap eventData)
		{
			SendRemoteEvent(node,new StringHash(eventType), inOrder, eventData);
		}

		void SendRemoteEvent(Node node, StringHash eventType, bool inOrder, DynamicMap eventData)
		{
			Connection_SendRemoteEvent2(handle,node.Handle,eventType.Code,inOrder,eventData.Handle);
		}
	}
}
