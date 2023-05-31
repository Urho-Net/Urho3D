using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class CallFuncND : CallFuncN
	{
		public Action<UIElement, object> CallFunctionND { get; }
		public object Data { get; }

		#region Constructors

		public CallFuncND(Action<UIElement, object> selector, object d) : base()
		{
			Data = d;
			CallFunctionND = selector;
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new CallFuncNDState (this, target);
		}
	}

	public class CallFuncNDState : CallFuncState
	{
		protected Action<UIElement, object> CallFunctionND { get; set; }
		protected object Data { get; set; }

		public CallFuncNDState (CallFuncND action, UIElement target)
			: base(action, target)
		{   
			CallFunctionND = action.CallFunctionND;
			Data = action.Data;
		}

		public override void Execute()
		{
			if (null != CallFunctionND)
			{
				CallFunctionND(Target, Data);
			}
		}
	}
}