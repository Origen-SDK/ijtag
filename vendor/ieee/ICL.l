/*
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/

%{
 
#include "ICL.h"
 
#include <stdio.h>
 
%}

 
%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault
 
%option noyywrap never-interactive nounistd
%option bison-bridge
 
%x COMMENT
 
%%
 
     
<COMMENT>{
[^*\n]*        /* consume anything that's not a '*' or newline */
"*"+[^*/\n]*   /* this pattern is similar to the previous one but
                           it also consumes 1 or more leading *'s. For example, if
                           the comment were "brad **** smiley" than the
                           first pattern would consume "brad " and this
                           pattern would consume "**** smiley". */
\n            { ++yylineno; }
"*"+"/"        { /* end of comment--resume initial state. Note that
                             this pattern specifies one or more "*"'s followed
                             by a "/", so it picks up comments ended by an
                             arbitrary number of *'s */
                          BEGIN(INITIAL); 
                        }
}
<INITIAL>{
	"/*"         BEGIN(COMMENT);
	[ \r\t]+            { /* Skip blanks. */ }
	[/][/][^\n]* { /* Skip comments. */ }
	\n { yylineno++; }

	AccessLink   return ACCESSLINK                      ;
	AccessTogether   return ACCESSTOGETHER                  ;
	ActivePolarity   return ACTIVEPOLARITY                  ;
	ActiveSignals   return ACTIVESIGNALS                   ;
	AddressPort   return ADDRESSPORT                     ;
	AddressValue   return ADDRESSVALUE                    ;
	Alias   return ALIAS                           ;
	AllowBroadcastOnScanInterface   return ALLOWBROADCASTONSCANINTERFACE   ;
	['][bB][ \t]*[01Xx][01Xx_]*   return UNSIZED_BIN_NUM                 ;
	['][dD][ \t]*[0-9][0-9_]*   return UNSIZED_DEC_NUM                 ;
	['][hH][ \t]*[0-9A-Fa-fXx][0-9A-Fa-fXx_]*   return UNSIZED_HEX_NUM                 ;
	&   return AND                             ;
	Attribute   return ATTRIBUTE                       ;
	BSDLEntity   return BSDLENTITIY                     ;
	CaptureEnPort   return CAPTUREENPORT                   ;
	CaptureSource   return CAPTURESOURCE                   ;
	Chain   return CHAIN                           ;
	ClockMux   return CLOCKMUX                        ;
	ClockPort   return CLOCKPORT                       ;
	:   return COLON                           ;
	\,   return COMMA                           ;
	DataInPort   return DATAINPORT                      ;
	DataMux   return DATAMUX                         ;
	DataOutPort   return DATAOUTPORT                     ;
	DataRegister   return DATAREGISTER                    ;
	DefaultLoadValue   return DEFAULTLOADVALUE                ;
	DifferentialInvOf   return DIFFERENTIALINVOF               ;
	[$]   return DOLLAR                          ;
	\.   return DOT                             ;
	::   return DOUBLE_COLON                    ;
	[<]D[>]   return D_SUBST                         ;
	Enable   return ENABLE                          ;
	Enum   return ENUM                            ;
	=   return EQUAL                           ;
	Falling   return FALLING                         ;
	FreqDivider   return FREQDIVIDER                     ;
	FreqMultiplier   return FREQMULTIPLIER                  ;
	iApplyEndState   return IAPPLYENDSTATE                  ;
	InputPort   return INPUTPORT                       ;
	Instance   return INSTANCE                        ;
	LaunchEdge   return LAUNCHEDGE                      ;
	\{   return LEFT_BRACE                      ;
	\[   return LEFT_BRACKET                    ;
	\(   return LEFT_PAREN                      ;
	LocalParameter   return LOCALPARAMETER                  ;
	LogicSignal   return LOGICSIGNAL                     ;
	&&   return LOGIC_AND                       ;
	==   return LOGIC_EQUAL                     ;
	[|][|]   return LOGIC_OR                        ;
	-   return MINUS                           ;
	Module   return MODULE                          ;
	ms   return MSEC                            ;
	NameSpace   return NAMESPACE                       ;
	!=   return NOT_EQUAL                       ;
	ns   return NSEC                            ;
	Of   return OF                              ;
	0   return ZERO                            ;
	1   return ONE                             ;
	OneHotDataGroup   return ONEHOTDATAGROUP                 ;
	OneHotScanGroup   return ONEHOTSCANGROUP                 ;
	Parameter   return PARAMETER                       ;
	%   return PERCENT                         ;
	Period   return PERIOD                          ;
	[|]   return PIPE                            ;
	[+]   return PLUS                            ;
	Port   return PORT                            ;
	[0-9][0-9_]*   return POS_INT                         ;
	ps   return PSEC                            ;
	ReadCallBack   return READCALLBACK                    ;
	ReadDataSource   return READDATASOURCE                  ;
	ReadEnPort   return READENPORT                      ;
	RefEnum   return REFENUM                         ;
	ResetPort   return RESETPORT                       ;
	ResetValue   return RESETVALUE                      ;
	\}   return RIGHT_BRACE                     ;
	]   return RIGHT_BRACKET                   ;
	[)]   return RIGHT_PAREN                     ;
	Rising   return RISING                          ;
	[<]R[>]   return R_SUBST                         ;
	ScanInPort   return SCANINPORT                      ;
	ScanInSource   return SCANINSOURCE                    ;
	ScanInterface   return SCANINTERFACE                   ;
	ScanMux   return SCANMUX                         ;
	ScanOutPort   return SCANOUTPORT                     ;
	ScanRegister   return SCANREGISTER                    ;
	s   return SEC                             ;
	SelectedBy   return SELECTEDBY                      ;
	SelectPort   return SELECTPORT                      ;
	;   return SEMICOLON                       ;
	ShiftEnPort   return SHIFTENPORT                     ;
	[/]   return SLASH                           ;
	Source   return SOURCE                          ;
	\*   return STAR                            ;
	STD_1149_1_2001   return STD_1149_1_2001                 ;
	STD_1149_1_2013   return STD_1149_1_2013                 ;
	\"(([^\"\\])|\\\\|\\)*\"  { return STRING                          ;}
	TCKPort   return TCKPORT                         ;
	~   return TILDE                           ;
	!   return LOGIC_NOT                       ;
	TMSPort   return TMSPORT                         ;
	ToCaptureEnPort   return TOCAPTUREENPORT                 ;
	ToClockPort   return TOCLOCKPORT                     ;
	ToIRSelectPort   return TOIRSELECTPORT                  ;
	ToResetPort   return TORESETPORT                     ;
	ToSelectPort   return TOSELECTPORT                    ;
	ToShiftEnPort   return TOSHIFTENPORT                   ;
	ToTCKPort   return TOTCKPORT                       ;
	ToTMSPort   return TOTMSPORT                       ;
	ToTRSTPort   return TOTRSTPORT                      ;
	ToUpdateEnPort   return TOUPDATEENPORT                  ;
	TRSTPort   return TRSTPORT                        ;
	UpdateEnPort   return UPDATEENPORT                    ;
	us   return USEC                            ;
	UseNameSpace   return USENAMESPACE                    ;
	WriteCallBack   return WRITECALLBACK                   ;
	WriteDataSource   return WRITEDATASOURCE                 ;
	WriteEnPort   return WRITEENPORT                     ;
	WriteEnSource   return WRITEENSOURCE                   ;
	[a-zA-Z][a-zA-Z0-9_]*   return SCALAR_ID                       ;
	\^   return XOR                             ;
	. { printf("lex Unknown character = '%s'", yytext); yyerror("lex Unknown character"); }
}

%%
 
