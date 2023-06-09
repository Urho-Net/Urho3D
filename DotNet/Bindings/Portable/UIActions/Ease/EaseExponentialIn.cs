using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseExponentialIn : ActionEase
	{
		#region Constructors

		public EaseExponentialIn (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseExponentialInState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseExponentialOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseExponentialInState : ActionEaseState
	{
		public EaseExponentialInState (EaseExponentialIn action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.ExponentialIn (time));
		}
	}

	#endregion Action state
}