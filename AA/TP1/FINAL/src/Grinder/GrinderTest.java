package Grinder;

import stone.AbstractGrinderTest;
import stone.Grinder;

public class GrinderTest extends AbstractGrinderTest {

	@Override
	protected Grinder makeGrinder() {
		
		return new MyGrinder();
	}

}
