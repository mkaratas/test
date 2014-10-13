package org.cjz.sample;

public class EventNotifier {
	private InterestingEvent ie;
	private boolean somethingHappened;

	public EventNotifier(InterestingEvent event) {
		ie = event;
		somethingHappened = false;
	}

	public void doWork() {
		if (somethingHappened) {
			ie.interestingEvent();
		}
	}

	public void setHappened() {
		somethingHappened = true;
	}
}
