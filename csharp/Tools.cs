using System;

namespace Cryptography.Tools
{
	public class GeneralTools
	{
		public static string ConvertBytesToString(Byte[] bytes)
		{
			int byteSize = bytes.Length;
	
			string hashString = null;

			for (int x = 0; x < byteSize; x++)	
				hashString += bytes[x].ToString("x2");

			return hashString;
		}
	
		public static bool InRange(long num, long min, long max)
		{
			return (num >= min && num < max); 
		}
	}
}
