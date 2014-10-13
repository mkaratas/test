package com.twoGenerics;

class Notepad<K, V> {
	private K mKey;
	private V mValue;

	public K getKey() {
		return this.mKey;
	}
	
	public V getValue() {
		return this.mValue;
	}

	public void setKey(K key) {
		this.mKey = key;
	}

	public void setValue(V value) {
		this.mValue = value;
	}
}

public class GenericsDemo {
	public static void main(String[] args) {
		Notepad<String, Integer> t = null;
		t = new Notepad<String, Integer>();
		t.setKey("fred");
		t.setValue(12);
		
		System.out.println("Key = "+t.getKey());
		System.out.println("Val = "+t.getValue());
	}
}
