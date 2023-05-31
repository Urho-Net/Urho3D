using Urho.Gui;
namespace Urho.UIActions
{
	public class ToggleVisibility : ActionInstant
	{
		#region Constructors

		public ToggleVisibility ()
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new ToggleVisibilityState (this, target);
		}
	}

	public class ToggleVisibilityState : ActionInstantState
	{
		public ToggleVisibilityState (ToggleVisibility action, UIElement target)
			: base (action, target)
		{
			target.Enabled = !target.Enabled;
			target.Visible = !target.Visible;
		}
	}
}