using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseSineOut : ActionEase
	{
		#region Constructors

		public EaseSineOut (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseSineOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseSineIn ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseSineOutState : ActionEaseState
	{
		public EaseSineOutState (EaseSineOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.SineOut (time));
		}
	}

	#endregion Action state
}