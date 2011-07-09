	import java.io.*;
	import java.net.URL;
	import java.net.*;
	public class FileDownloader
	{
		public static void main(String args[])
		{
			
			if(args.length != 2 && !(args[0].equals(""))){
				System.out.println("Usage: <web-link> <new-filename>");
			}else{try{
				//java.io.BufferedInputStream in = new java.io.BufferedInputStream(new URL("http://cl.thapar.edu/qp/CH016.pdf").openStream());
				if((args[0].substring(7,10)).equals("172"))
					args[0] = "http://cl.thapar.edu/" + args[0].substring(20);
				System.out.println("FileDownloader: "+args[0]+" "+args[1]);
				URL url = new URL(args[0]);
				java.io.BufferedInputStream in = new java.io.BufferedInputStream(url.openStream());
				java.io.FileOutputStream fos = new java.io.FileOutputStream(args[1]+".pdf");
				java.io.BufferedOutputStream bout = new BufferedOutputStream(fos,1024);
				byte[] data = new byte[1024];
				int x=0;
				while((x=in.read(data,0,1024))>=0)
				{
					bout.write(data,0,x);
				}
				bout.close();
				in.close();
			}catch(IOException e){
				System.out.println(e.toString());
			}}
		}
	}