//hasResources.cpp

#include <stdio.h>
#include <memory>
#include <string.h>
#include <SupportDefs.h>
#include <String.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>
#include <Application.h>
#include <Rect.h>
#include <Message.h>
#include <MenuItem.h>
#include <MenuBar.h>
#include <PopUpMenu.h>
#include <Window.h>
#include <View.h>
#include <SupportDefs.h>
#include <Beep.h>
#include <List.h>
#include <TextControl.h>
#include <TextView.h>
#include <ScrollView.h>
#include <Font.h>
#include <OS.h>
#include <Button.h>
#include <StatusBar.h>
#include <CheckBox.h>
#include <PictureButton.h>
#include <ColorControl.h>
#include <RadioButton.h>
#include <Point.h>
#include <TypeConstants.h>
#include <ListView.h>
#include <GraphicsDefs.h>
#include <File.h>
#include <Screen.h>
#include <Alert.h>
#include <Resources.h>
#include <StringView.h>
#include <Path.h>
const char * ResEDgarVersion = "Resourceful 1.0.1, Ed Musgrove, BeDev#2076";

class 
MyApp	:
public	BApplication
{
private:

			MyApp(	const MyApp& copy);//not implemented on purpose
	MyApp&	operator = (	const MyApp& assign);//not implemented on purpose
public:
			MyApp();
			~MyApp();
	void	ReadyToRun(	void);
};

MyApp	::	MyApp()
		:	BApplication("application/x-vnd.EFM5.Resourceful")
{
	//left blank
}//end

MyApp	::	~MyApp(){/*left blank*/}//end

void 
MyApp	::	ReadyToRun(	void) 
{
	BResources * appResources = AppResources();
	size_t len;
	char * str = (char *)appResources->FindResource('CSTR', "aResource", &len);
	printf("%s\n", str);
	free (str);
	PostMessage(B_QUIT_REQUESTED);
}//end
int 
main(	void) 
{
	MyApp my_app;
	my_app.Run();
	return B_OK;
}//end