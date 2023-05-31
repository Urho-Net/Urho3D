using Urho.Gui;

namespace Urho.UIActions
{
	public class MoveBy : FiniteTimeAction
	{
		#region Constructors

		public MoveBy (float duration, Vector2 position) : base (duration)
		{
			PositionDelta = position;
		}

		#endregion Constructors

		public Vector2 PositionDelta { get; private set; }

		protected internal override ActionState StartAction(UIElement target)
		{
			return new MoveByState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new MoveBy (Duration, new Vector2(-PositionDelta.X, -PositionDelta.Y));
		}
	}

	public class MoveByState : FiniteTimeActionState
	{
		protected Vector2 PositionDelta;
		protected Vector2 EndPosition;
		protected Vector2 StartPosition;
		protected Vector2 PreviousPosition;

		public MoveByState (MoveBy action, UIElement target)
			: base (action, target)
		{ 
			PositionDelta = action.PositionDelta;
			PreviousPosition = StartPosition = target.Position.CastF();
		}

		public override void Update (float time)
		{
			if (Target == null)
				return;

			var currentPos = Target.Position.CastF();
			var diff = currentPos - PreviousPosition;
			StartPosition = StartPosition + diff;
			Vector2 newPos = StartPosition + PositionDelta * time;
			Target.Position = newPos.CastI();
			PreviousPosition = newPos;
		}
	}

}