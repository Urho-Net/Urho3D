using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseBounceIn : ActionEase
	{
		#region Constructors

		public EaseBounceIn (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseBounceInState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseBounceOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseBounceInState : ActionEaseState
	{
		public EaseBounceInState (EaseBounceIn action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.BounceIn (time));
		}
	}

	#endregion Action state
}