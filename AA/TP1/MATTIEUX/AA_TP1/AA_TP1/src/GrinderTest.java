import stone.AbstractGrinderTest;
import stone.Grinder;
import stone.Stone;

public class GrinderTest extends AbstractGrinderTest  {

	@Override
	protected Grinder makeGrinder() {
		return new MyGrinder();
	}

	
}