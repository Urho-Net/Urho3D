using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseBounceOut : ActionEase
	{
		#region Constructors

		public EaseBounceOut (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseBounceOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseBounceIn ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseBounceOutState : ActionEaseState
	{
		public EaseBounceOutState (EaseBounceOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.BounceOut (time));
		}
	}

	#endregion Action state
}