using System.Diagnostics;
using Urho.Gui;

namespace Urho.UIActions
{
	public class ReverseTime : FiniteTimeAction
	{
		public FiniteTimeAction Other { get; private set; }


		#region Constructors

		public ReverseTime (FiniteTimeAction action) : base (action.Duration)
		{
			Other = action;
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new ReverseTimeState (this, target);

		}

		public override FiniteTimeAction Reverse ()
		{
			return Other;
		}
	}

	public class ReverseTimeState : FiniteTimeActionState
	{

		protected FiniteTimeAction Other { get; set; }

		protected FiniteTimeActionState OtherState { get; set; }

		public ReverseTimeState (ReverseTime action, UIElement target)
			: base (action, target)
		{   
			Other = action.Other;
			OtherState = (FiniteTimeActionState)Other.StartAction (target);
		}

		protected internal override void Stop ()
		{
			OtherState.Stop ();
		}

		public override void Update (float time)
		{
			if (Other != null)
			{
				OtherState.Update (1 - time);
			}
		}

	}

}