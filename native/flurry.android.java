
import com.flurry.android.FlurryAgent;

class BBFlurry implements Runnable{

	static BBFlurry _flurry;
	
	static byte _gm = 1;
	static byte _gf = 0;
	
	Activity _flurryactivity;
	
	static public BBFlurry GetFlurry(){
		if( _flurry==null ) _flurry=new BBFlurry();
		return _flurry;
	}
	
	public void onStartSession(){
		_flurryactivity = BBAndroidGame.AndroidGame().GetActivity();
		FlurryAgent.onStartSession(_flurryactivity, MonkeyConfig.FLURRY_APIKEY);

	}
	
	public void onEndSession(){
		FlurryAgent.onEndSession(_flurryactivity);
	}
	
	public void logEvent( String eventId){
		FlurryAgent.logEvent(eventId);
	}
	
	public void setUserID( String userID){
		FlurryAgent.setUserId(userID);
	}
	
	public void setAge( int age){
		FlurryAgent.setAge(age);
	}
	
	public void setGender( String gender){
		if( gender=="m" ){
			FlurryAgent.setGender(_gm);
			}
		else {
			FlurryAgent.setGender(_gf);
			};
	}
	
	public void logEvent( String eventId, String[] params){
	
		Map<String, String> flurryParams = new HashMap<String, String>();
        for(int i=0;i<params.length;i=i+2)
    		flurryParams.put(params[i], params[i+1]);
        FlurryAgent.logEvent(eventId, flurryParams);
	}
	
	public void logEvent( String eventId, boolean timed){
		FlurryAgent.logEvent(eventId, timed);
	}
	
	public void logEvent( String eventId, String[] params, boolean timed){
		Map<String, String> flurryParams = new HashMap<String, String>();
        for(int i=0;i<params.length;i=i+2)
    		flurryParams.put(params[i], params[i+1]);
		FlurryAgent.logEvent(eventId, flurryParams, timed);
	}
	
	public void setLogEnabled( boolean logFlag){
		FlurryAgent.setLogEnabled(logFlag);
	}
	
	public void onError(String errorId, String message, String errorClass){
		FlurryAgent.onError(errorId, message, errorClass);
	}
	
	public void onPageView(){
		FlurryAgent.onPageView();
	}

	public void run(){
	}
	
}
