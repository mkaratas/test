package org.cjz.sample;

public class Test {
	public static void main(String [] args) {
		EventNotifier en = new EventNotifier(new CallMe());
		en.setHappened();
		en.doWork();
	}
}
