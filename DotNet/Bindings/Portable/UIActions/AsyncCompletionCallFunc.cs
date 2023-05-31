using System;

using Urho.Gui;
namespace Urho.UIActions
{
	class AsyncCompletionCallFunc : CallFunc
	{
		#region Constructors

		public AsyncCompletionCallFunc(Action selector) : base(selector)
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new AsyncCompletionCallFuncState(this, target);
		}
	}

	class AsyncCompletionCallFuncState : CallFuncState
	{
		public AsyncCompletionCallFuncState(CallFunc action, UIElement target)
			: base(action, target)
		{
		}

		internal protected override void Stop()
		{
			CallFunction?.Invoke();
		}
	}
}