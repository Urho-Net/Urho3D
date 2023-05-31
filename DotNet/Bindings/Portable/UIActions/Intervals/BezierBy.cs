using System;

using Urho.Gui;

namespace Urho.UIActions
{
	public class BezierBy : FiniteTimeAction
	{
		public BezierConfig BezierConfig { get; private set; }


		#region Constructors

		public BezierBy (float t, BezierConfig config) : base (t)
		{
			BezierConfig = config;
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new BezierByState (this, target);

		}

		public override FiniteTimeAction Reverse ()
		{
			BezierConfig r;

			r.EndPosition = -BezierConfig.EndPosition;
			r.ControlPoint1 = BezierConfig.ControlPoint2 + -BezierConfig.EndPosition;
			r.ControlPoint2 = BezierConfig.ControlPoint1 + -BezierConfig.EndPosition;

			var action = new BezierBy (Duration, r);
			return action;
		}
	}

	public class BezierByState : FiniteTimeActionState
	{
		protected BezierConfig BezierConfig { get; set; }

		protected Vector2 StartPosition { get; set; }

		protected Vector2 PreviousPosition { get; set; }


		public BezierByState (BezierBy action, UIElement target)
			: base (action, target)
		{ 
			BezierConfig = action.BezierConfig;
			PreviousPosition = StartPosition = new Vector2(target.Position.X,target.Position.Y);
		}

		public override void Update (float time)
		{
			if (Target != null)
			{
				float xa = 0;
				float xb = BezierConfig.ControlPoint1.X;
				float xc = BezierConfig.ControlPoint2.X;
				float xd = BezierConfig.EndPosition.X;

				float ya = 0;
				float yb = BezierConfig.ControlPoint1.Y;
				float yc = BezierConfig.ControlPoint2.Y;
				float yd = BezierConfig.EndPosition.Y;


				float x = SplineMath.CubicBezier (xa, xb, xc, xd, time);
				float y = SplineMath.CubicBezier (ya, yb, yc, yd, time);
		
				Vector2 currentPos = Target.Position.CastF();
				Vector2 diff = currentPos - PreviousPosition;
				StartPosition = StartPosition + diff;

				Vector2 newPos = StartPosition + new Vector2(x,y);
				Target.Position = newPos.CastI();

				PreviousPosition = newPos;
			}
		}

	}

	public struct BezierConfig
	{
		public Vector2 ControlPoint1;
		public Vector2 ControlPoint2;
		public Vector2 EndPosition;
	}
}