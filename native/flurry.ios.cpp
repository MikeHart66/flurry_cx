
#import "libs/Flurry.h"

class BBFlurry{

	static BBFlurry *_flurry;
	int _state;
	
public:
	BBFlurry();
	
	static BBFlurry *GetFlurry();
	
	void onStartSession();
	void onEndSession();
	void logEvent(String eventId);
	void logEvent(String eventId, Array<class String> params);
	void logEvent(String eventId, BOOL timed);
	void logEvent(String eventId, Array<class String> params, BOOL timed);
	void setLogEnabled(int logFlag);
	void onError(String errorId, String message, String errorClass);
	void onPageView();
	void setUserID(String userID);	
	void setAge(NSInteger age);	
	void setGender(String gender);	
	
};

//flurry.ios.cpp

#define _QUOTE(X) #X
#define _STRINGIZE(X) _QUOTE(X)

BBFlurry *BBFlurry::_flurry;

BBFlurry::BBFlurry():_state(-1){
	_state=0;
}

BBFlurry *BBFlurry::GetFlurry(){
	if( !_flurry ) _flurry=new BBFlurry();
	return _flurry;
}


void BBFlurry::onStartSession(){
	NSString* apiKey = @_STRINGIZE(CFG_FLURRY_APIKEY);
	[Flurry startSession:apiKey];
}

void BBFlurry::onEndSession(){
	//not supported in IOS
	//[Flurry endSession];
}

void BBFlurry::logEvent(String eventId){
	[Flurry logEvent:eventId.ToNSString()];
}

void BBFlurry::logEvent(String eventId, Array<class String> params){
	NSMutableDictionary *myDictionary = [[NSMutableDictionary alloc] init];

	for (int i = 0; i < sizeof(params) / sizeof(params[0]); i=i+2){
		[myDictionary setObject:params[i].ToNSString() forKey:params[i+1].ToNSString()];
	};
	[Flurry logEvent:eventId.ToNSString() withParameters:myDictionary];
}

void BBFlurry::logEvent(String eventId, BOOL timed){
	if (timed == TRUE) {
		[Flurry logEvent:eventId.ToNSString() timed:YES];
		}
	else
		[Flurry logEvent:eventId.ToNSString()];
}

void BBFlurry::setUserID(String userID){
	[Flurry setUserID:userID.ToNSString()];
}

void BBFlurry::setGender(String gender){
	[Flurry setGender:gender.ToNSString()];
}

void BBFlurry::setAge(NSInteger age){
	[Flurry setAge:age];
}

void BBFlurry::logEvent(String eventId, Array<class String> params, BOOL timed){
	NSMutableDictionary *myDictionary = [[NSMutableDictionary alloc] init];

	for (int i = 0; i < sizeof(params) ; i=i+2){
		[myDictionary setObject:params[i].ToNSString() forKey:params[i+1].ToNSString()];
	};

	if (timed == TRUE) {
		[Flurry logEvent:eventId.ToNSString() withParameters:myDictionary timed:YES];
		}
	else
		[Flurry logEvent:eventId.ToNSString() withParameters:myDictionary];
}

void BBFlurry::setLogEnabled(int logFlag){
//Not supported in iOS
}

void BBFlurry::onError(String errorId, String message, String errorClass){
    NSException *e = [NSException

        exceptionWithName:errorClass.ToNSString()

        reason:message.ToNSString()

        userInfo:nil];

	[Flurry logError:errorId.ToNSString() message:message.ToNSString() exception:e];
}

void BBFlurry::onPageView(){
	[Flurry logPageView];
}



