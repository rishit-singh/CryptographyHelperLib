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
		public static string ConvertBytesToString(Byte[] bytes)
		{
			int byteSize = bytes.Length;
	
			string hashString = null;

			for (int x = 0; x < byteSize; x++)	
				hashString += bytes[x].ToString("x2");

			return hashString;
		}

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

			return Hashing.ConvertBytesToString(SHA256Managed.Create().ComputeHash(Encoding.UTF8.GetBytes(str)));
		}
	}
}
