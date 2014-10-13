package org.cjz.sample;

public class CallMe implements InterestingEvent {
	private EventNotifier en;

	public CallMe() {
		en = new EventNotifier(this);
	}

	public void interestingEvent() {
		System.out.println("Call me Hello.");
	}
}
