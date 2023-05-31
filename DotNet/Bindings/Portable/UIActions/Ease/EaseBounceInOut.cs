using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseBounceInOut : ActionEase
	{
		#region Constructors

		public EaseBounceInOut (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseBounceInOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseBounceInOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseBounceInOutState : ActionEaseState
	{
		public EaseBounceInOutState (EaseBounceInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.BounceInOut (time));
		}
	}

	#endregion Action state
}