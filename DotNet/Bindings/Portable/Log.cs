using System;

namespace Urho.IO
{
	public unsafe partial class Log : UrhoObject
	{
        const string RedColorBackground = "\u001b[41m";
        const string GreenColorBackground = "\u001b[42m";
        const string YellowColorBackground = "\u001b[43m";
        const string BlueColorBackground = "\u001b[44m";
        const string PurpleColorBackground = "\u001b[45m";
        const string CyanColorBackground = "\u001b[46m";
        
        const string RedColorText = "\u001b[31m";
        const string GreenColorText = "\u001b[32m";
        const string YellowColorText = "\u001b[33m";
        const string BlueColorText = "\u001b[34m";
        const string PurpleColorText = "\u001b[35m";
        const string CyanColorText = "\u001b[36m";

        public  LogLevel LogLevel
        {
            get
            {
                if (Application.Current != null)
                {
                    return (LogLevel)Application.Log.GetLevel();
                }
                else
                {
                    return LogLevel.None;
                }
            }
            set
            {
                if (Application.Current != null)
                {
                    Application.Log.SetLevel((int)value);
                }
            }
        }

        public static LogLevel StaticLogLevel
        {
            get
            {
                if (Application.Current != null)
                {
                    return (LogLevel)Application.Log.GetLevel();
                }
                else
                {
                    return LogLevel.None;
                }
            }
            set
            {
                if (Application.Current != null)
                {
                    Application.Log.SetLevel((int)value);
                }
            }
        }

        private static int s_indentLevel;
        public static int IndentLevel
        {
            get
            {
                return s_indentLevel;
            }
            set
            {
                s_indentLevel = value < 0 ? 0 : value;
            }
        }

        private static int s_indentSize = 4;
        public static int IndentSize
        {
            get
            {
                return s_indentSize;
            }
            set
            {
                s_indentSize = value < 0 ? 0 : value;
            }
        }

        public static void Indent()
        {
            IndentLevel++;
        }

        public static void Unindent()
        {
            IndentLevel--;
        }

        private static bool s_needIndent;

        private static string s_indentString;

		// public static LogLevel LogLevel { get; set; } = LogLevel.Debug;

        public static void Error(string str) =>  LogSharpWrite(LogLevel.Error, str);
        public  void Error(string str , int dummy = 0) =>  LogSharpWrite(LogLevel.Error, str);
		public static void Error(string str, Exception exc) =>  LogSharpWrite(LogLevel.Error, $"Exception: {exc}. " + str);
        public  void Error(string str, Exception exc ,int dummy = 0) =>  LogSharpWrite(LogLevel.Error, $"Exception: {exc}. " + str);
		public static void Warn(string str) =>  LogSharpWrite(LogLevel.Warning, str);
        public  void Warn(string str,int dummy = 0 ) =>  LogSharpWrite(LogLevel.Warning, str);

        public static void Debug(string str) =>  LogSharpWrite(LogLevel.Debug, str);
        public  void Debug(string str,int dummy = 0) => LogSharpWrite(LogLevel.Debug, str);
        
		public static void Info(string str) =>  LogSharpWrite(LogLevel.Info, str);
        public  void Info(string str , int dummy = 0) =>  LogSharpWrite(LogLevel.Info, str);

        public static void Print(string message) =>  LogSharpWrite(LogLevel.Debug,message);
        
        public  void Print(string message , int dummy = 0 ) =>  LogSharpWrite(LogLevel.Debug,message);

        public static void Assert(bool condition) =>  Assert(condition, string.Empty, string.Empty);
        
        public  void Assert(bool condition , int dummy = 0) =>  Assert(condition, string.Empty, string.Empty);

        public static void Assert(bool condition, string message) =>  Assert(condition, message, string.Empty);
        public  void Assert(bool condition, string message , int dummy = 0 ) =>  Assert(condition, message, string.Empty);

        public static void Assert(bool condition, string message, string detailMessage)
        {
            if (!condition)
            {
                WriteLine(LogLevel.Error,FormatAssert(Environment.StackTrace, message, detailMessage));
            }
        }

        public  void Assert(bool condition, string message, string detailMessage , int dummy =0) => Assert( condition,  message,  detailMessage);

        public static void WriteLine(LogLevel level,string message, string category)
        {
            if (level < StaticLogLevel)return;

            if (category == null)
            {
                WriteLine(level,message);
            }
            else
            {
                WriteLine(level,category + ":" + message);
            }
        }

        public  void WriteLine(LogLevel level,string message, string category , int dummy = 0) => WriteLine( level, message,  category);

        public static void WriteLine(LogLevel level,string format, object arg0)
        {
           if (level < StaticLogLevel)return;
           WriteLine(level,String.Format(format,arg0));
        }

        public void WriteLine(LogLevel level,string format, object arg0 , int dummy =0 ) => WriteLine( level, format,  arg0);
        public void WriteLine(string format, object arg0 , int dummy =0 ) => WriteLine( LogLevel.Info, format,  arg0);
        public static void WriteLine(string format, object arg0) => WriteLine(LogLevel.Info, format,  arg0);

        public static void WriteLine(LogLevel level,string format, object arg0, object arg1)
        {
           if (level < StaticLogLevel)return;
           WriteLine(level,String.Format(format,arg0,arg1));
        }
        public  void WriteLine(LogLevel level,string format, object arg0, object arg1 , int dummy = 0 ) => WriteLine( level, format,  arg0,  arg1);
        public  void WriteLine(string format, object arg0, object arg1 , int dummy = 0 ) => WriteLine( LogLevel.Info, format,  arg0,  arg1);
        public  static void WriteLine(string format, object arg0, object arg1 ) => WriteLine( LogLevel.Info, format,  arg0,  arg1);

        public static void WriteLine(LogLevel level,string format, object arg0, object arg1, object arg2)
        {
           if (level < StaticLogLevel)return;
           WriteLine(level,String.Format(format,arg0,arg1,arg2));
        }
        public  void WriteLine(LogLevel level,string format, object arg0, object arg1, object arg2 , int dummy = 0 ) => WriteLine( level, format,  arg0,  arg1,  arg2);
        public  void WriteLine(string format, object arg0, object arg1, object arg2, int dummy = 0 ) => WriteLine(  LogLevel.Info, format,  arg0,  arg1,  arg2);
        public static void WriteLine(string format, object arg0, object arg1, object arg2  ) => WriteLine(  LogLevel.Info, format,  arg0,  arg1,  arg2);

        public static void WriteLine(LogLevel level,string message)
        {
            if (level < StaticLogLevel)return;
             LogSharpWrite(level,message + Environment.NewLine);
        }

        public  void WriteLine(LogLevel level,string message , int dummy = 0) => WriteLine( level, message);
        public  void WriteLine(string message , int dummy = 0) => WriteLine( LogLevel.Info, message);
        public static void WriteLine(string message ) => WriteLine( LogLevel.Info, message);

        private static string FormatAssert(string stackTrace, string message, string detailMessage)
        {
            string newLine = GetIndentString() + Environment.NewLine;
            return  message + newLine
                   + detailMessage + newLine
                   + stackTrace;
        }

        private static string GetIndentString()
        {
            int indentCount = IndentSize * IndentLevel;
            if (s_indentString?.Length == indentCount)
            {
                return s_indentString;
            }
            return s_indentString = new string(' ', indentCount);
        }

        private static void LogSharpWrite(LogLevel level, string message)
        {
            if (level < StaticLogLevel || message == null)
                return;

            if (s_needIndent)
            {
                message = GetIndentString() + message;
                s_needIndent = false;
            }

            if (message.EndsWith(Environment.NewLine))
            {
                s_needIndent = true;
            }

#if __ANDROID__
            switch(level)
            {
                case LogLevel.Raw:
                case LogLevel.Debug:
                    Urho.IO.Log.Write(LogLevel.Info,message);
                break;
                
               
                case LogLevel.Info:
                case LogLevel.Warning:
			        Urho.IO.Log.Write(level,message);
                break;

                // sending LogLevel.Error is causing Android crash
                case LogLevel.Error:
			        Urho.IO.Log.Write(LogLevel.Warning,message);
                break;
            }

#else
#if __IOS__
            
            switch (level)
            {
                case LogLevel.Info:
                case LogLevel.Raw:
                case LogLevel.Debug:
                    System.Console.WriteLine("📗"+$"{level}: {message}");
                break;

                case LogLevel.Warning:
                    System.Console.WriteLine("📙"+$"{level}: {message}");
                break;
                case LogLevel.Error:
                    System.Console.WriteLine("📕" +$"{level}: {message}");
                break;
            }
#else
            var timestamp = "[" + DateTime.Now.ToString("MM/dd/yyyy hh:mm:ss.fff") + "] ";

            switch (level)
            {
                case LogLevel.Info:
                case LogLevel.Raw:
                case LogLevel.Debug:
                     System.Console.WriteLine($"{timestamp} {level}: {message}");
                break;

                case LogLevel.Warning:
                     System.Console.WriteLine(YellowColorText+$"{timestamp} {level}: {message}");
                break;
                case LogLevel.Error:
			        System.Console.WriteLine(RedColorText + $"{timestamp} {level}: {message}");
                break;
            }
            
#if __EDITOR__
            if (Application.HasCurrent)
                Application.Current.OnLogSharpHook(level, message);
#endif

#endif
#endif
        }

	}
}
