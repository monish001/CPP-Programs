//File: QPDownloader.java
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

public class QPDownloader{
	public static void main(String[] args){
		//String patternString = "";
		String input = (new DownloadHTML("http://cl.thapar.edu/library_qp.html")).getHTML();

		/*Pattern pattern = Pattern.compile(patternString);
		Matcher matcher = pattern.matcher(input);
		if (matcher.matches()){
		
		}*/
		System.out.println(input);
	}
}
class DownloadHTML{
	DownloadHTML(String web_link){
		try{
			// Here we give the URL for the Crawler
			URL url = new URL(web_link);

			strbuf = new StringBuffer();
			System.setProperty("http.proxyHost","");
			System.setProperty("http.proxyPort", "");
			URLConnection conn = url.openConnection();
			DataInputStream in = new DataInputStream ( conn.getInputStream ( ) ) ;
			BufferedReader d = new BufferedReader(new InputStreamReader(in));
			while(d.ready())
			{
				//System.out.println(d.readLine());
				strbuf.append(d.readLine()+"\n");
			}
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
	String getHTML()
	{
		return strbuf.toString();
	}
	
	private StringBuffer strbuf;
}