using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class CallFuncN : CallFunc
	{
		public Action<UIElement> CallFunctionN { get; }

		#region Constructors

		public CallFuncN()
		{
		}

		public CallFuncN(Action<UIElement> selector) : base()
		{
			CallFunctionN = selector;
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new CallFuncNState (this, target);

		}
	}

	public class CallFuncNState : CallFuncState
	{
		protected Action<UIElement> CallFunctionN { get; set; }

		public CallFuncNState (CallFuncN action, UIElement target)
			: base(action, target)
		{   
			CallFunctionN = action.CallFunctionN;
		}

		public override void Execute()
		{
			CallFunctionN?.Invoke(Target);
		}
	}
}