/*
*
* This Class crawls the specified URL page
*package javacrawlersystem;/**
*
* @author Arpit.Sharma
*/
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.Iterator;
public class HTMLCodeDownloader 
{/**
* @param args the command line arguments
*/
	public static void main(String[] args)
	{// TODO code application logic here
		try
		{
			// This creates the test.txt file
			File newFile=new File("C:/Documents and Settings/Usual Account/Desktop/test3.html");
			// Here we give the URL for the Crawler
			URL url = new URL("http://cl.thapar.edu/library_qp05.html");
			FileOutputStream fop=new FileOutputStream(newFile);//
			ArrayList<String> htmlLine=new ArrayList<String>();
			System.setProperty("http.proxyHost","");
			System.setProperty("http.proxyPort", "");
			URLConnection conn = url.openConnection();
			DataInputStream in = new DataInputStream ( conn.getInputStream ( ) ) ;
			BufferedReader d = new BufferedReader(new InputStreamReader(in));
			while(d.ready())
			{
				//System.out.println(d.readLine());
				htmlLine.add(d.readLine()+"\n");
			}
			Iterator itr=htmlLine.iterator();
			while(itr.hasNext())
			{
				fop.write(((String)(itr.next())).getBytes());
			}
			fop.flush();
			fop.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}