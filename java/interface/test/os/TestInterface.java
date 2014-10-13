package test.os;

public class TestInterface {
	public static void main(String[] args) {
		TestInterface t = new TestInterface();

		CareAnimalable c = new Worker();
		t.t(c);
	
		c = new Farmer();
		t.t(c);
	}

	public void t(CareAnimalable c) {
		c.feed();
		c.play();
	}
}

interface CareAnimalable {
	public void feed();
	public void play();
}

class Worker implements CareAnimalable {
	public void feed() {
		System.out.println("---------feed()-------------");
	}
	
	public void play() {
		System.out.println("---------play()-------------");
	}
}

class Farmer implements CareAnimalable {
	public void feed() {
		System.out.println("---------Farmer feed()-------------");
	}

	public void play() {
		System.out.println("---------Farmer play()-------------");
	}
}
