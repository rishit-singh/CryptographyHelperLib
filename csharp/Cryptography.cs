using System;
using System.Text;
using System.Security.Cryptography;

namespace Cryptography
{
	/// <summary>
	/// Contains string hashing functions. 
	/// </summary>
	public class Hashing
	{
		public static string GetSHA256(string str)
		{
			try
			{
				if (str == null)
					throw new NullReferenceException();
			}
			catch (NullReferenceException)
			{
				return str;
			}
			 
			string hashString = null;
			
			Byte[] hashBytes = null; 	
	
			int byteSize = 0;

			Encoding encoding = Encoding.UTF8;

			SHA256 sha256 = SHA256Managed.Create();

			hashBytes = sha256.ComputeHash(encoding.GetBytes(str));

			byteSize = hashBytes.Length;

			for (int x = 0; x < byteSize; x++)	
				hashString += hashBytes[x].ToString("x2");
			
			return hashString;
		}
	}
}
