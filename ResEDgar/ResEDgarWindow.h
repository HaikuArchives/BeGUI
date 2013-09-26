//resEdWindow.h

#ifndef RESEDWINDOW
#define RESEDWINDOW
	#define ABOUT_RESEDWINDOW 'eDrW'
	#define SAVE 'Save'
	class TitleWindow;
	
	class ResEdWindow :
	public ScrollingWindow
	{
	private:
							ResEdWindow(		const ResEdWindow& copy);//not implimented on purpose
		ResEdWindow&		operator = (	const ResEdWindow& assign);//not implimented on purpose
		BList *				mpEditList;
		BFile *				mpFile;
		bool				mbJustClose;
		BResources			resources;
	public:
							ResEdWindow(	BRect paramBound,
											const char * paramWindowTitle,
											const char * paramScrollViewName,
											const char * paramNamePrefFrame,
											TitleWindow * paramTitleWindow,
											bool * success,
											BFile * paramFile);
							~ResEdWindow();
		virtual bool		QuitRequested(		void);
		virtual void		MessageReceived(	BMessage *	pparamMessage);
		bool				Save(	void);
		TitleWindow *		mpTitleWindow;
	};
#endif