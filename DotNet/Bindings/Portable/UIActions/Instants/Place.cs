using Urho.Gui;
namespace Urho.UIActions
{
	public class Place : ActionInstant
	{
		public IntVector2 Position { get; }

		#region Constructors

		public Place (IntVector2 pos)
		{
			Position = pos;
		}

		public Place (int posX, int posY)
		{
			Position = new IntVector2(posX, posY);
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new PlaceState (this, target);
		}
	}

	public class PlaceState : ActionInstantState
	{
		public PlaceState (Place action, UIElement target)
			: base (action, target)
		{ 
			Target.Position = action.Position;
		}
	}
}