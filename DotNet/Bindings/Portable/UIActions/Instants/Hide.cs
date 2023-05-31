using Urho.Gui;
namespace Urho.UIActions
{
	public class Hide : ActionInstant
	{
		#region Constructors

		public Hide ()
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new HideState (this, target);

		}

		public override FiniteTimeAction Reverse ()
		{
			return (new Show ());
		}
	}

	public class HideState : ActionInstantState
	{
		public HideState (Hide action, UIElement target)
			: base (action, target)
		{   
			target.Enabled = false;
			target.Visible = false;
		}
	}
}