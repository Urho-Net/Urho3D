using Urho.Gui;

namespace Urho.UIActions
{
	public class EaseBackInOut : ActionEase
	{
		#region Constructors

		public EaseBackInOut(FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseBackInOutState (this, target);
		}

		public override FiniteTimeAction Reverse()
		{
			return new EaseBackInOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseBackInOutState : ActionEaseState
	{
		public EaseBackInOutState (EaseBackInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.BackInOut (time));
		}
	}

	#endregion Action state
}