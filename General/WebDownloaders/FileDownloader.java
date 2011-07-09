	import java.io.*;
	import java.net.*;
	public class FileDownloader
	{
		public static void main(String args[]) throws IOException
		{
			
			java.io.BufferedInputStream in = new java.io.BufferedInputStream(new
			java.net.URL("http://cl.thapar.edu/qp/CH016.pdf").openStream());
			java.io.FileOutputStream fos = new java.io.FileOutputStream("t  est.pdf");
			java.io.BufferedOutputStream bout = new BufferedOutputStream(fos,1024);
			byte[] data = new byte[1024];
			int x=0;
			while((x=in.read(data,0,1024))>=0)
			{
				bout.write(data,0,x);
			}
			bout.close();
			in.close();
		}
	}