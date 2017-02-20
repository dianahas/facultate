package utils;

public class IdLockGener {
	private static int counter = 0;
	public static int generator(){
		return ++counter;
	}
}
