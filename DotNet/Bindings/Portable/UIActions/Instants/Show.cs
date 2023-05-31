using Urho.Gui;
namespace Urho.UIActions
{
	public class Show : ActionInstant
	{
		protected internal override ActionState StartAction(UIElement target)
		{
			return new ShowState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return (new Hide ());
		}
	}

	public class ShowState : ActionInstantState
	{
		public ShowState (Show action, UIElement target)
			: base (action, target)
		{
			target.Enabled = true;
			target.Visible = true;
		}
	}
}