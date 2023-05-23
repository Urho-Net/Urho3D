﻿using System.Linq;
using System.Runtime.InteropServices;
//using Foundation;

namespace Urho.iOS
{
	public static class IosUrhoInitializer
	{
		[DllImport(Consts.NativeImport)]
		static extern void InitSdl(string resDir, string docDir);

		internal static void OnInited()
		{
			//string docsDir = NSSearchPath.GetDirectories(NSSearchPathDirectory.DocumentDirectory, NSSearchPathDomain.All, true).FirstOrDefault();
			//string resourcesDir = NSBundle.MainBundle.ResourcePath;
			string docsDir = "";
			string resourcesDir = "";

			InitSdl(resourcesDir, docsDir);
			Sdl.SetMainReady();
			//NSFileManager.DefaultManager.ChangeCurrentDirectory(resourcesDir);
		}
	}
}