#pragma once
#using <System.dll>
#include "Status.h"
#include "Levels.h"
#include "SharedVariables.h"

int FWidth, FHeight;
double ballXspd = 5.0, ballYspd = -5.0, ballX, ballY;
bool ballMoving = false;

template <class X> X Max(X a, X b)
{
	return (a>b)?a:b;
}

template <class X> X Min(X a, X b)
{
	return (a<b)?a:b;
}

template <class X> X Limit(X val, X min, X max)
{
	return Min(max, Max(min, val));
}


namespace WinGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		array<Button ^, 2> ^Bricks;
		Boolean moving, deactivated, bonusfall, firing;
		int prevLeft, prevTop;

	private: System::Windows::Forms::Label^  Message;
	private: System::Windows::Forms::CheckBox^  Bonus;
	private: System::Windows::Forms::TrackBar^  Fire;
	private: System::Windows::Forms::Timer^  NextLevel;


			 Status ^statusWindow;
	public:
		Form1(void)
		{
			InitializeComponent();
			FWidth = this->ClientSize.Width;
			FHeight = this->ClientSize.Height;
			Bricks = gcnew array<Button ^, 2>(10, 30);
			ballX = Ball->Left;
			ballY = Ball->Right;
			moving = deactivated = bonusfall = false;
			Ball->BackColor = Color::Transparent;
			//Message->BackColor = Color::Transparent;
			for(int i = 0; i < 10; i++)
				for(int n = 0; n < 30; n++)
				{
					Bricks[i, n] = gcnew Button();
					Bricks[i, n]->Width = FWidth/10;
					Bricks[i, n]->Height = FHeight/30;
					Bricks[i, n]->Left = (FWidth/10)*i;
					Bricks[i, n]->Top = (FHeight/30)*n;
					Bricks[i, n]->Parent = this;
					Bricks[i, n]->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 6.5);
				}
			LoadLevel(level);

			statusWindow = gcnew Status();
			statusWindow->Show(this);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^  Paddle;
	protected: 
	private: System::Windows::Forms::RadioButton^  Ball;
	private: System::Windows::Forms::Timer^  Update;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Paddle = (gcnew System::Windows::Forms::ProgressBar());
			this->Ball = (gcnew System::Windows::Forms::RadioButton());
			this->Update = (gcnew System::Windows::Forms::Timer(this->components));
			this->Message = (gcnew System::Windows::Forms::Label());
			this->Bonus = (gcnew System::Windows::Forms::CheckBox());
			this->Fire = (gcnew System::Windows::Forms::TrackBar());
			this->NextLevel = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Fire))->BeginInit();
			this->SuspendLayout();
			// 
			// Paddle
			// 
			this->Paddle->Enabled = false;
			this->Paddle->Location = System::Drawing::Point(2, 560);
			this->Paddle->Name = L"Paddle";
			this->Paddle->Size = System::Drawing::Size(151, 17);
			this->Paddle->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			this->Paddle->TabIndex = 0;
			// 
			// Ball
			// 
			this->Ball->AutoSize = true;
			this->Ball->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Ball->Checked = true;
			this->Ball->Location = System::Drawing::Point(82, 220);
			this->Ball->Margin = System::Windows::Forms::Padding(0);
			this->Ball->Name = L"Ball";
			this->Ball->Size = System::Drawing::Size(14, 13);
			this->Ball->TabIndex = 1;
			this->Ball->TabStop = true;
			this->Ball->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Ball->UseVisualStyleBackColor = false;
			// 
			// Update
			// 
			this->Update->Enabled = true;
			this->Update->Interval = 15;
			this->Update->Tick += gcnew System::EventHandler(this, &Form1::Update_Tick);
			// 
			// Message
			// 
			this->Message->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Message->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Message->Enabled = false;
			this->Message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Message->Location = System::Drawing::Point(15, 263);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(570, 75);
			this->Message->TabIndex = 2;
			this->Message->Text = L"Click To Start";
			this->Message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Message->Move += gcnew System::EventHandler(this, &Form1::Message_Move);
			// 
			// Bonus
			// 
			this->Bonus->AutoSize = true;
			this->Bonus->Location = System::Drawing::Point(32, 219);
			this->Bonus->Name = L"Bonus";
			this->Bonus->Size = System::Drawing::Size(15, 14);
			this->Bonus->TabIndex = 3;
			this->Bonus->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Bonus->UseVisualStyleBackColor = true;
			this->Bonus->Visible = false;
			// 
			// Fire
			// 
			this->Fire->AutoSize = false;
			this->Fire->Location = System::Drawing::Point(32, 257);
			this->Fire->Name = L"Fire";
			this->Fire->Size = System::Drawing::Size(27, 27);
			this->Fire->TabIndex = 4;
			this->Fire->Visible = false;
			// 
			// NextLevel
			// 
			this->NextLevel->Interval = 1000;
			this->NextLevel->Tick += gcnew System::EventHandler(this, &Form1::NextLevel_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 600);
			this->Controls->Add(this->Fire);
			this->Controls->Add(this->Bonus);
			this->Controls->Add(this->Message);
			this->Controls->Add(this->Ball);
			this->Controls->Add(this->Paddle);
			this->Cursor = System::Windows::Forms::Cursors::SizeWE;
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Winoid beta";
			this->Deactivate += gcnew System::EventHandler(this, &Form1::Form1_Deactivate);
			this->Activated += gcnew System::EventHandler(this, &Form1::Form1_Activated);
			this->Click += gcnew System::EventHandler(this, &Form1::Form1_Click);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Fire))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
			 }
	private: System::Void Update_Tick(System::Object^  sender, System::EventArgs^  e) {
				 // calculated paused variable from various pause events
				 paused = moving || deactivated || (totalbricks == destroyedbricks);
				 if(moving || deactivated)
					 Message->Text = "Paused";
				 else if(totalbricks == destroyedbricks)
					 Message->Text = "Level Complete!";
				 else
					 Message->Text = "Click to Start";

				 Paddle->Value += 2;
				 if(Paddle->Value == Paddle->Maximum)
					 Paddle->Value = 0;

				 if(!paused)
					 Paddle->Left = Limit(MousePosition.X-this->Left - (this->Width-this->ClientSize.Width)/2 - Paddle->Width/2,
					 0, FWidth - Paddle->Width);

				 //Update message
				 Message->Visible = !ballMoving || paused;

				 //Update bonus
				 Bonus->Visible = bonusfall;
				 if(bonusfall)
				 {
					 Bonus->Top += 7;
					 if(Bonus->Top > this->Height)
						 bonusfall = false;

					 //detect collision with paddle
					 if(Bonus->Left+Bonus->Width >= Paddle->Left && Bonus->Left < Paddle->Left+Paddle->Width &&
						 Bonus->Top+Bonus->Height >= Paddle->Top && Bonus->Top < Paddle->Top+Paddle->Height)
					 {
						 gotBonus = true;
						 bonusfall = false;
					 }
				 }

				 //Update ball position
				 if(ballMoving)
				 {
					if(!paused)
					{
						ballX += ballXspd;
						ballY += ballYspd;
					}

					Ball->Left = ballX;
					Ball->Top = ballY;
				 }
				 else
				 {
					 Ball->Left = ballX = Paddle->Left+Paddle->Width/2-Ball->Width/2;
					 Ball->Top = ballY = Paddle->Top-Ball->Height*1.5;
				 }

				 //Handle bounce against walls
				 if(Ball->Left <= 0)
				 {
					 Ball->Left = 0;
					 ballXspd = Math::Abs(ballXspd);
					 System::Media::SystemSounds::Beep->Play();
				 }
				 if(Ball->Left >= FWidth)
				 {
					 Ball->Left = FWidth;
					 ballXspd = -Math::Abs(ballXspd);
					 System::Media::SystemSounds::Beep->Play();
				 }
				 if(Ball->Top <= 0)
				 {
					 Ball->Top = 0;
					 ballYspd = Math::Abs(ballYspd);
					 System::Media::SystemSounds::Beep->Play();
				 }

				 if(Ball->Top > FHeight)
				 {
					 ballMoving = false;
					 System::Media::SystemSounds::Exclamation->Play();
					 if(!(--lives))
						 Close();
				 }

				 //Handle paddle collision
				 if(Ball->Top+Ball->Height >= Paddle->Top && Ball->Top <= Paddle->Top+Paddle->Height &&
					 Ball->Left+Ball->Width >= Paddle->Left && Ball->Left <= Paddle->Left + Paddle->Width)
				 {
					 ballYspd = -Math::Abs(ballYspd);
					 ballXspd = ((Ball->Left+Ball->Width/2.0) - (Paddle->Left+Paddle->Width/2.0))/10.0;
					 System::Media::SystemSounds::Beep->Play();
				 }

				 //Handle firing
				 if(firing)
				 {
					 Fire->Top -= 8;
					 if(Fire->Top+Fire->Height < 0)
						 firing = false;
				 }

				 //Resolve brick collision
				 int bX = Limit((Ball->Left+Ball->Width/2)/(FWidth/10), 0, 9),
					 bY = Limit((Ball->Top+Ball->Height/2)/(FHeight/30), 0, 29);

				 for(int c = 0; c < 1+(firing); c++)
				 {
					if(Bricks[bX, bY]->Visible)
					{
						if(Bricks[bX, bY]->Enabled)
						{
							Bricks[bX, bY]->Visible = false;
							System::Media::SystemSounds::Asterisk->Play();

							//Add score
							double s;
							Double::TryParse(Bricks[bX, bY]->Text, s);
							score += s;

							//generate bonus randomly
							if(!bonusfall && rand()%1000 < 25)
							{
								bonusfall = true;
								Bonus->Left = Bricks[bX, bY]->Left+Bricks[bX, bY]->Width/2;
								Bonus->Top = Bricks[bX, bY]->Top;
							}

							destroyedbricks++;

							// Detect, if the level is completed
							if(destroyedbricks == totalbricks)
								NextLevel->Enabled = true;
						}
						
						if(c == 0)
						{
							//Bounce ball
							/*if(Ball->Left+Ball->Width > Bricks[bX, bY]->Left+Ball->Width && Ball->Left < Bricks[bX, bY]->Left + Bricks[bX, bY]->Width-Ball->Width)
								ballYspd *= -1;
							else
								ballXspd *= -1;	*/

							int brickXcenter = Bricks[bX, bY]->Left+Bricks[bX, bY]->Width/2,
								brickYcenter = Bricks[bX, bY]->Top+Bricks[bX, bY]->Height/2,
								ballXcenter = Ball->Left+Ball->Width/2,
								ballYcenter = Ball->Top+Ball->Height/2,
								positionQ;


							/* positionQ	position quadrant
								0	2
								1	3	*/

							if(ballXcenter < brickXcenter)
							{
								if(ballYcenter < brickYcenter)
									positionQ = 0;
								else
									positionQ = 1;
							}
							else
							{
								if(ballYcenter < brickYcenter)
									positionQ = 2;
								else
									positionQ = 3;
							}

							switch(positionQ)
							{
							// top left
							case 0:
								if( (Bricks[bX, bY]->Left-Ball->Left) < (Bricks[bX, bY]->Top-Ball->Top))
									ballYspd = -abs(ballYspd);
								else
									ballXspd = -abs(ballXspd);
								break;
							// down left
							case 1:
								if( (Bricks[bX, bY]->Left-Ball->Left) < 
									( (Ball->Top+Ball->Height)-(Bricks[bX, bY]->Top+Bricks[bX, bY]->Height) ))
									ballYspd = abs(ballYspd);
								else
									ballXspd = -abs(ballXspd);
								break;
							// top right
							case 2:
								if( ( (Ball->Left+Ball->Width) - (Bricks[bX, bY]->Left+Bricks[bX, bY]->Width) ) < 
									(Bricks[bX, bY]->Top-Ball->Top) )
									ballYspd = -abs(ballYspd);
								else
									ballXspd = abs(ballXspd);
								break;
							// down right
							case 3:
								if( ( (Ball->Left+Ball->Width) - (Bricks[bX, bY]->Left+Bricks[bX, bY]->Width) ) < 
									( (Ball->Top+Ball->Height)-(Bricks[bX, bY]->Top+Bricks[bX, bY]->Height) ) )
									ballYspd = abs(ballYspd);
								else
									ballXspd = abs(ballXspd);
								break;

							}
						}
					}

					bX = Limit((Fire->Left+Fire->Width/2.0)/(FWidth/10.0), 0.0, 9.0),
					bY = Limit((Fire->Top+Fire->Height/2.0)/(FHeight/30.0), 0.0, 29.0);
				 }

				 //Update lives count
				 for(int i = 0; i < 10; i++)
					 statusWindow->LivesMeter[i]->Checked = lives>i;

				 //Reset moving variable
				 moving = (prevLeft-this->Left)+(prevTop-this->Top);
				 prevLeft = this->Left;
				 prevTop = this->Top;
			 }

	private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) {
				 ballMoving = true;
				 if(gotBonus && !firing)
				 {
					 firing = true;
					 gotBonus = false;
					 Fire->Visible = true;
					 Fire->Left = Paddle->Left+Paddle->Width/2-Fire->Width/2;
					 Fire->Top = Paddle->Top-Fire->Height;
				 }
			 }
private: System::Void Form1_Activated(System::Object^  sender, System::EventArgs^  e) {
			 deactivated = false;
		 }
private: System::Void Form1_Deactivate(System::Object^  sender, System::EventArgs^  e) {
			 deactivated = true;
		 }
private: System::Void Message_Move(System::Object^  sender, System::EventArgs^  e) {
		 }



		 void LoadLevel(int level)
		 {
			 level = Limit(level, 0, LevelCount-1);

			 totalbricks = destroyedbricks = 0;
			 ballMoving = false;

			 for(int x = 0; x < 10; x++)
				 for(int y = 0; y < 30; y++)
				 {
					 // Set brick to default state at first
					 Bricks[x,y]->Visible = true;
					 Bricks[x,y]->Enabled = true;
					 Bricks[x,y]->Text	  = "";

					 if(Levels[level][y][x] == 0)
					 {
						 Bricks[x,y]->Visible = false;
						 continue;
					 }

					 if(Levels[level][y][x] < 0)
					 {
						 Bricks[x,y]->Enabled = false;
						 continue;
					 }

					 Bricks[x,y]->Text = Levels[level][y][x].ToString();
					 totalbricks++;
				 }
		 }
private: System::Void NextLevel_Tick(System::Object^  sender, System::EventArgs^  e) {
			 LoadLevel(++level);
			 NextLevel->Enabled = false;
		 }
};
}

