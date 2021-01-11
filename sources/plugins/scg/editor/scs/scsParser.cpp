
#include "scsLexer.h"
#include "scs_parser.hpp"

#define APPEND_ATTRS(__attrs, __edge) \
for (auto const & _a : __attrs) \
{ \
  ElementHandle const attrEdge = m_parser->ProcessConnector(_a.second ? "->" : "_->"); \
  m_parser->ProcessTriple(_a.first, attrEdge, __edge); \
}

#define PARSE_ERROR(line, pos, msg) \
  SC_THROW_EXCEPTION(utils::ExceptionParseError, \
                    "line " << line << ", " << pos << " " << msg);



// Generated from scs.g4 by ANTLR 4.7.1



#include "scsParser.h"


using namespace antlrcpp;
using namespace scs;
using namespace antlr4;

scsParser::scsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

scsParser::~scsParser() {
  delete _interpreter;
}

std::string scsParser::getGrammarFileName() const {
  return "scs.g4";
}

const std::vector<std::string>& scsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& scsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ContentContext ------------------------------------------------------------------

scsParser::ContentContext::ContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::ContentContext::CONTENT_BODY() {
  return getToken(scsParser::CONTENT_BODY, 0);
}


size_t scsParser::ContentContext::getRuleIndex() const {
  return scsParser::RuleContent;
}


scsParser::ContentContext* scsParser::content() {
  ContentContext *_localctx = _tracker.createInstance<ContentContext>(_ctx, getState());
  enterRule(_localctx, 0, scsParser::RuleContent);
   _localctx->isVar = false; 
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scsParser::T__0) {
      setState(48);
      match(scsParser::T__0);
       _localctx->isVar = true; 
    }
    setState(52);
    dynamic_cast<ContentContext *>(_localctx)->c = match(scsParser::CONTENT_BODY);

          std::string const v = _localctx->c->getText();
          //SC_ASSERT(v.size() > 1, ());
          _localctx->handle = m_parser->ProcessContent(v.substr(1, v.size() - 2), _localctx->isVar);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContourContext ------------------------------------------------------------------

scsParser::ContourContext::ContourContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::ContourContext::CONTOUR_BEGIN() {
  return getToken(scsParser::CONTOUR_BEGIN, 0);
}

tree::TerminalNode* scsParser::ContourContext::CONTOUR_END() {
  return getToken(scsParser::CONTOUR_END, 0);
}

std::vector<scsParser::Sentence_wrapContext *> scsParser::ContourContext::sentence_wrap() {
  return getRuleContexts<scsParser::Sentence_wrapContext>();
}

scsParser::Sentence_wrapContext* scsParser::ContourContext::sentence_wrap(size_t i) {
  return getRuleContext<scsParser::Sentence_wrapContext>(i);
}


size_t scsParser::ContourContext::getRuleIndex() const {
  return scsParser::RuleContour;
}


scsParser::ContourContext* scsParser::contour() {
  ContourContext *_localctx = _tracker.createInstance<ContourContext>(_ctx, getState());
  enterRule(_localctx, 2, scsParser::RuleContour);
   dynamic_cast<ContourContext *>(_localctx)->count =  1; 
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(scsParser::CONTOUR_BEGIN);

          m_parser->ProcessContourBegin();
        
    setState(57);

    if (!( _localctx->count > 0 )) throw FailedPredicateException(this, " $ctx->count > 0 ");

    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__0)
      | (1ULL << scsParser::T__42)
      | (1ULL << scsParser::T__44)
      | (1ULL << scsParser::T__45)
      | (1ULL << scsParser::T__46)
      | (1ULL << scsParser::T__47)
      | (1ULL << scsParser::T__48)
      | (1ULL << scsParser::T__49)
      | (1ULL << scsParser::T__50)
      | (1ULL << scsParser::T__51)
      | (1ULL << scsParser::T__52)
      | (1ULL << scsParser::T__53)
      | (1ULL << scsParser::T__55)
      | (1ULL << scsParser::T__57))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (scsParser::ID_SYSTEM - 64))
      | (1ULL << (scsParser::ALIAS_SYMBOLS - 64))
      | (1ULL << (scsParser::CONTOUR_BEGIN - 64))
      | (1ULL << (scsParser::CONTENT_BODY - 64))
      | (1ULL << (scsParser::LINK - 64)))) != 0)) {
      setState(58);
      sentence_wrap();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(scsParser::CONTOUR_END);

          _localctx->count--;
          if (_localctx->count == 0)
          {
            _localctx->handle = m_parser->ProcessContourEnd();
          }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContourWithJoinContext ------------------------------------------------------------------

scsParser::ContourWithJoinContext::ContourWithJoinContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::ContourWithJoinContext::CONTOUR_BEGIN() {
  return getToken(scsParser::CONTOUR_BEGIN, 0);
}

tree::TerminalNode* scsParser::ContourWithJoinContext::CONTOUR_END() {
  return getToken(scsParser::CONTOUR_END, 0);
}

std::vector<scsParser::Sentence_wrapContext *> scsParser::ContourWithJoinContext::sentence_wrap() {
  return getRuleContexts<scsParser::Sentence_wrapContext>();
}

scsParser::Sentence_wrapContext* scsParser::ContourWithJoinContext::sentence_wrap(size_t i) {
  return getRuleContext<scsParser::Sentence_wrapContext>(i);
}


size_t scsParser::ContourWithJoinContext::getRuleIndex() const {
  return scsParser::RuleContourWithJoin;
}


scsParser::ContourWithJoinContext* scsParser::contourWithJoin() {
  ContourWithJoinContext *_localctx = _tracker.createInstance<ContourWithJoinContext>(_ctx, getState());
  enterRule(_localctx, 4, scsParser::RuleContourWithJoin);
   dynamic_cast<ContourWithJoinContext *>(_localctx)->count =  1; 
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(scsParser::CONTOUR_BEGIN);

          m_parser->ProcessContourBegin();
        
    setState(69);

    if (!( _localctx->count > 0 )) throw FailedPredicateException(this, " $ctx->count > 0 ");

    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__0)
      | (1ULL << scsParser::T__42)
      | (1ULL << scsParser::T__44)
      | (1ULL << scsParser::T__45)
      | (1ULL << scsParser::T__46)
      | (1ULL << scsParser::T__47)
      | (1ULL << scsParser::T__48)
      | (1ULL << scsParser::T__49)
      | (1ULL << scsParser::T__50)
      | (1ULL << scsParser::T__51)
      | (1ULL << scsParser::T__52)
      | (1ULL << scsParser::T__53)
      | (1ULL << scsParser::T__55)
      | (1ULL << scsParser::T__57))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (scsParser::ID_SYSTEM - 64))
      | (1ULL << (scsParser::ALIAS_SYMBOLS - 64))
      | (1ULL << (scsParser::CONTOUR_BEGIN - 64))
      | (1ULL << (scsParser::CONTENT_BODY - 64))
      | (1ULL << (scsParser::LINK - 64)))) != 0)) {
      setState(70);
      sentence_wrap();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(scsParser::CONTOUR_END);

          _localctx->count--;
          if (_localctx->count == 0)
          {
            //_localctx->handle = m_parser->ProcessContourEnd();
          }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectorContext ------------------------------------------------------------------

scsParser::ConnectorContext::ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t scsParser::ConnectorContext::getRuleIndex() const {
  return scsParser::RuleConnector;
}


scsParser::ConnectorContext* scsParser::connector() {
  ConnectorContext *_localctx = _tracker.createInstance<ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 6, scsParser::RuleConnector);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    dynamic_cast<ConnectorContext *>(_localctx)->c = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__1)
      | (1ULL << scsParser::T__2)
      | (1ULL << scsParser::T__3)
      | (1ULL << scsParser::T__4)
      | (1ULL << scsParser::T__5)
      | (1ULL << scsParser::T__6)
      | (1ULL << scsParser::T__7)
      | (1ULL << scsParser::T__8)
      | (1ULL << scsParser::T__9)
      | (1ULL << scsParser::T__10)
      | (1ULL << scsParser::T__11)
      | (1ULL << scsParser::T__12)
      | (1ULL << scsParser::T__13)
      | (1ULL << scsParser::T__14)
      | (1ULL << scsParser::T__15)
      | (1ULL << scsParser::T__16)
      | (1ULL << scsParser::T__17)
      | (1ULL << scsParser::T__18)
      | (1ULL << scsParser::T__19)
      | (1ULL << scsParser::T__20)
      | (1ULL << scsParser::T__21)
      | (1ULL << scsParser::T__22)
      | (1ULL << scsParser::T__23)
      | (1ULL << scsParser::T__24)
      | (1ULL << scsParser::T__25)
      | (1ULL << scsParser::T__26)
      | (1ULL << scsParser::T__27)
      | (1ULL << scsParser::T__28)
      | (1ULL << scsParser::T__29)
      | (1ULL << scsParser::T__30)
      | (1ULL << scsParser::T__31)
      | (1ULL << scsParser::T__32)
      | (1ULL << scsParser::T__33)
      | (1ULL << scsParser::T__34)
      | (1ULL << scsParser::T__35)
      | (1ULL << scsParser::T__36)
      | (1ULL << scsParser::T__37)
      | (1ULL << scsParser::T__38)
      | (1ULL << scsParser::T__39)
      | (1ULL << scsParser::T__40))) != 0))) {
      dynamic_cast<ConnectorContext *>(_localctx)->c = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

          _localctx->text = dynamic_cast<ConnectorContext *>(_localctx)->c->getText();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SyntaxContext ------------------------------------------------------------------

scsParser::SyntaxContext::SyntaxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::SyntaxContext::EOF() {
  return getToken(scsParser::EOF, 0);
}

std::vector<scsParser::Sentence_wrapContext *> scsParser::SyntaxContext::sentence_wrap() {
  return getRuleContexts<scsParser::Sentence_wrapContext>();
}

scsParser::Sentence_wrapContext* scsParser::SyntaxContext::sentence_wrap(size_t i) {
  return getRuleContext<scsParser::Sentence_wrapContext>(i);
}


size_t scsParser::SyntaxContext::getRuleIndex() const {
  return scsParser::RuleSyntax;
}


scsParser::SyntaxContext* scsParser::syntax() {
  SyntaxContext *_localctx = _tracker.createInstance<SyntaxContext>(_ctx, getState());
  enterRule(_localctx, 8, scsParser::RuleSyntax);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__0)
      | (1ULL << scsParser::T__42)
      | (1ULL << scsParser::T__44)
      | (1ULL << scsParser::T__45)
      | (1ULL << scsParser::T__46)
      | (1ULL << scsParser::T__47)
      | (1ULL << scsParser::T__48)
      | (1ULL << scsParser::T__49)
      | (1ULL << scsParser::T__50)
      | (1ULL << scsParser::T__51)
      | (1ULL << scsParser::T__52)
      | (1ULL << scsParser::T__53)
      | (1ULL << scsParser::T__55)
      | (1ULL << scsParser::T__57))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (scsParser::ID_SYSTEM - 64))
      | (1ULL << (scsParser::ALIAS_SYMBOLS - 64))
      | (1ULL << (scsParser::CONTOUR_BEGIN - 64))
      | (1ULL << (scsParser::CONTENT_BODY - 64))
      | (1ULL << (scsParser::LINK - 64)))) != 0)) {
      setState(82);
      sentence_wrap();
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
    match(scsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_wrapContext ------------------------------------------------------------------

scsParser::Sentence_wrapContext::Sentence_wrapContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::SentenceContext* scsParser::Sentence_wrapContext::sentence() {
  return getRuleContext<scsParser::SentenceContext>(0);
}


size_t scsParser::Sentence_wrapContext::getRuleIndex() const {
  return scsParser::RuleSentence_wrap;
}


scsParser::Sentence_wrapContext* scsParser::sentence_wrap() {
  Sentence_wrapContext *_localctx = _tracker.createInstance<Sentence_wrapContext>(_ctx, getState());
  enterRule(_localctx, 10, scsParser::RuleSentence_wrap);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    sentence();
    setState(91);
    match(scsParser::T__41);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SentenceContext ------------------------------------------------------------------

scsParser::SentenceContext::SentenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Sentence_lvl1Context* scsParser::SentenceContext::sentence_lvl1() {
  return getRuleContext<scsParser::Sentence_lvl1Context>(0);
}

scsParser::Sentence_assignContext* scsParser::SentenceContext::sentence_assign() {
  return getRuleContext<scsParser::Sentence_assignContext>(0);
}

scsParser::Sentence_assign_contourContext* scsParser::SentenceContext::sentence_assign_contour() {
  return getRuleContext<scsParser::Sentence_assign_contourContext>(0);
}

scsParser::Sentence_lvl_commonContext* scsParser::SentenceContext::sentence_lvl_common() {
  return getRuleContext<scsParser::Sentence_lvl_commonContext>(0);
}


size_t scsParser::SentenceContext::getRuleIndex() const {
  return scsParser::RuleSentence;
}


scsParser::SentenceContext* scsParser::sentence() {
  SentenceContext *_localctx = _tracker.createInstance<SentenceContext>(_ctx, getState());
  enterRule(_localctx, 12, scsParser::RuleSentence);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      sentence_lvl1();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(94);
      sentence_assign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(95);
      sentence_assign_contour();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(96);
      sentence_lvl_common();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasContext ------------------------------------------------------------------

scsParser::AliasContext::AliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::AliasContext::ALIAS_SYMBOLS() {
  return getToken(scsParser::ALIAS_SYMBOLS, 0);
}


size_t scsParser::AliasContext::getRuleIndex() const {
  return scsParser::RuleAlias;
}


scsParser::AliasContext* scsParser::alias() {
  AliasContext *_localctx = _tracker.createInstance<AliasContext>(_ctx, getState());
  enterRule(_localctx, 14, scsParser::RuleAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(scsParser::ALIAS_SYMBOLS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_systemContext ------------------------------------------------------------------

scsParser::Idtf_systemContext::Idtf_systemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scsParser::Idtf_systemContext::ID_SYSTEM() {
  return getToken(scsParser::ID_SYSTEM, 0);
}

scsParser::Idtf_lvl1_preffixContext* scsParser::Idtf_systemContext::idtf_lvl1_preffix() {
  return getRuleContext<scsParser::Idtf_lvl1_preffixContext>(0);
}


size_t scsParser::Idtf_systemContext::getRuleIndex() const {
  return scsParser::RuleIdtf_system;
}


scsParser::Idtf_systemContext* scsParser::idtf_system() {
  Idtf_systemContext *_localctx = _tracker.createInstance<Idtf_systemContext>(_ctx, getState());
  enterRule(_localctx, 16, scsParser::RuleIdtf_system);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scsParser::ID_SYSTEM: {
        enterOuterAlt(_localctx, 1);
        setState(101);
        dynamic_cast<Idtf_systemContext *>(_localctx)->id_systemToken = match(scsParser::ID_SYSTEM);
         _localctx->handle = m_parser->ProcessIdentifier(dynamic_cast<Idtf_systemContext *>(_localctx)->id_systemToken->getText()); 
        break;
      }

      case scsParser::T__42: {
        enterOuterAlt(_localctx, 2);
        setState(103);
        match(scsParser::T__42);
         _localctx->handle = m_parser->ProcessIdentifier("..."); 
        break;
      }

      case scsParser::T__44:
      case scsParser::T__45:
      case scsParser::T__46:
      case scsParser::T__47:
      case scsParser::T__48:
      case scsParser::T__49:
      case scsParser::T__50:
      case scsParser::T__51:
      case scsParser::T__52:
      case scsParser::T__53: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        dynamic_cast<Idtf_systemContext *>(_localctx)->type = idtf_lvl1_preffix();
         _localctx->handle = m_parser->ProcessIdentifier(_localctx->type->text); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_assignContext ------------------------------------------------------------------

scsParser::Sentence_assignContext::Sentence_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::AliasContext* scsParser::Sentence_assignContext::alias() {
  return getRuleContext<scsParser::AliasContext>(0);
}

scsParser::Idtf_commonContext* scsParser::Sentence_assignContext::idtf_common() {
  return getRuleContext<scsParser::Idtf_commonContext>(0);
}


size_t scsParser::Sentence_assignContext::getRuleIndex() const {
  return scsParser::RuleSentence_assign;
}


scsParser::Sentence_assignContext* scsParser::sentence_assign() {
  Sentence_assignContext *_localctx = _tracker.createInstance<Sentence_assignContext>(_ctx, getState());
  enterRule(_localctx, 18, scsParser::RuleSentence_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    dynamic_cast<Sentence_assignContext *>(_localctx)->a = alias();
    setState(111);
    match(scsParser::T__43);
    setState(112);
    dynamic_cast<Sentence_assignContext *>(_localctx)->i = idtf_common();

          m_parser->ProcessAssign(_localctx->a->getText(), _localctx->i->handle);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_assign_contourContext ------------------------------------------------------------------

scsParser::Sentence_assign_contourContext::Sentence_assign_contourContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Idtf_commonContext* scsParser::Sentence_assign_contourContext::idtf_common() {
  return getRuleContext<scsParser::Idtf_commonContext>(0);
}

scsParser::ContourWithJoinContext* scsParser::Sentence_assign_contourContext::contourWithJoin() {
  return getRuleContext<scsParser::ContourWithJoinContext>(0);
}


size_t scsParser::Sentence_assign_contourContext::getRuleIndex() const {
  return scsParser::RuleSentence_assign_contour;
}


scsParser::Sentence_assign_contourContext* scsParser::sentence_assign_contour() {
  Sentence_assign_contourContext *_localctx = _tracker.createInstance<Sentence_assign_contourContext>(_ctx, getState());
  enterRule(_localctx, 20, scsParser::RuleSentence_assign_contour);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    dynamic_cast<Sentence_assign_contourContext *>(_localctx)->a = idtf_common();
    setState(116);
    match(scsParser::T__43);
    setState(117);
    dynamic_cast<Sentence_assign_contourContext *>(_localctx)->i = contourWithJoin();

          m_parser->ProcessContourEndWithJoin(_localctx->a->handle);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_lvl1_preffixContext ------------------------------------------------------------------

scsParser::Idtf_lvl1_preffixContext::Idtf_lvl1_preffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t scsParser::Idtf_lvl1_preffixContext::getRuleIndex() const {
  return scsParser::RuleIdtf_lvl1_preffix;
}


scsParser::Idtf_lvl1_preffixContext* scsParser::idtf_lvl1_preffix() {
  Idtf_lvl1_preffixContext *_localctx = _tracker.createInstance<Idtf_lvl1_preffixContext>(_ctx, getState());
  enterRule(_localctx, 22, scsParser::RuleIdtf_lvl1_preffix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    dynamic_cast<Idtf_lvl1_preffixContext *>(_localctx)->type = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__44)
      | (1ULL << scsParser::T__45)
      | (1ULL << scsParser::T__46)
      | (1ULL << scsParser::T__47)
      | (1ULL << scsParser::T__48)
      | (1ULL << scsParser::T__49)
      | (1ULL << scsParser::T__50)
      | (1ULL << scsParser::T__51)
      | (1ULL << scsParser::T__52)
      | (1ULL << scsParser::T__53))) != 0))) {
      dynamic_cast<Idtf_lvl1_preffixContext *>(_localctx)->type = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

        _localctx->text = _localctx->type->getText();
      
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_lvl1_valueContext ------------------------------------------------------------------

scsParser::Idtf_lvl1_valueContext::Idtf_lvl1_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Idtf_lvl1_preffixContext* scsParser::Idtf_lvl1_valueContext::idtf_lvl1_preffix() {
  return getRuleContext<scsParser::Idtf_lvl1_preffixContext>(0);
}

tree::TerminalNode* scsParser::Idtf_lvl1_valueContext::ID_SYSTEM() {
  return getToken(scsParser::ID_SYSTEM, 0);
}


size_t scsParser::Idtf_lvl1_valueContext::getRuleIndex() const {
  return scsParser::RuleIdtf_lvl1_value;
}


scsParser::Idtf_lvl1_valueContext* scsParser::idtf_lvl1_value() {
  Idtf_lvl1_valueContext *_localctx = _tracker.createInstance<Idtf_lvl1_valueContext>(_ctx, getState());
  enterRule(_localctx, 24, scsParser::RuleIdtf_lvl1_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    dynamic_cast<Idtf_lvl1_valueContext *>(_localctx)->type = idtf_lvl1_preffix();
    setState(124);
    match(scsParser::T__54);
    setState(125);
    dynamic_cast<Idtf_lvl1_valueContext *>(_localctx)->i = match(scsParser::ID_SYSTEM);

          _localctx->handle = m_parser->ProcessIdentifierLevel1(_localctx->type->text, _localctx->i->getText());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_lvl1Context ------------------------------------------------------------------

scsParser::Idtf_lvl1Context::Idtf_lvl1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Idtf_lvl1_valueContext* scsParser::Idtf_lvl1Context::idtf_lvl1_value() {
  return getRuleContext<scsParser::Idtf_lvl1_valueContext>(0);
}


size_t scsParser::Idtf_lvl1Context::getRuleIndex() const {
  return scsParser::RuleIdtf_lvl1;
}


scsParser::Idtf_lvl1Context* scsParser::idtf_lvl1() {
  Idtf_lvl1Context *_localctx = _tracker.createInstance<Idtf_lvl1Context>(_ctx, getState());
  enterRule(_localctx, 26, scsParser::RuleIdtf_lvl1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    dynamic_cast<Idtf_lvl1Context *>(_localctx)->idtf_lvl1_valueContext = idtf_lvl1_value();
     _localctx->handle = dynamic_cast<Idtf_lvl1Context *>(_localctx)->idtf_lvl1_valueContext->handle; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_edgeContext ------------------------------------------------------------------

scsParser::Idtf_edgeContext::Idtf_edgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scsParser::Idtf_commonContext *> scsParser::Idtf_edgeContext::idtf_common() {
  return getRuleContexts<scsParser::Idtf_commonContext>();
}

scsParser::Idtf_commonContext* scsParser::Idtf_edgeContext::idtf_common(size_t i) {
  return getRuleContext<scsParser::Idtf_commonContext>(i);
}

scsParser::ConnectorContext* scsParser::Idtf_edgeContext::connector() {
  return getRuleContext<scsParser::ConnectorContext>(0);
}

scsParser::Attr_listContext* scsParser::Idtf_edgeContext::attr_list() {
  return getRuleContext<scsParser::Attr_listContext>(0);
}


size_t scsParser::Idtf_edgeContext::getRuleIndex() const {
  return scsParser::RuleIdtf_edge;
}


scsParser::Idtf_edgeContext* scsParser::idtf_edge() {
  Idtf_edgeContext *_localctx = _tracker.createInstance<Idtf_edgeContext>(_ctx, getState());
  enterRule(_localctx, 28, scsParser::RuleIdtf_edge);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(scsParser::T__55);
    setState(132);
    dynamic_cast<Idtf_edgeContext *>(_localctx)->src = idtf_common();
    setState(133);
    dynamic_cast<Idtf_edgeContext *>(_localctx)->c = connector();
    setState(135);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(134);
      dynamic_cast<Idtf_edgeContext *>(_localctx)->attrs = attr_list();
      break;
    }

    }
    setState(137);
    dynamic_cast<Idtf_edgeContext *>(_localctx)->trg = idtf_common();
    setState(138);
    match(scsParser::T__56);

          ElementHandle const edge = m_parser->ProcessConnector(_localctx->c->text);
          m_parser->ProcessTriple(_localctx->src->handle, edge, _localctx->trg->handle);

          // append attributes
          if (_localctx->attrs != nullptr)
          {
            APPEND_ATTRS(dynamic_cast<Idtf_edgeContext *>(_localctx)->attrs->items, edge);
          }

          _localctx->handle = edge;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_setContext ------------------------------------------------------------------

scsParser::Idtf_setContext::Idtf_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scsParser::Idtf_commonContext *> scsParser::Idtf_setContext::idtf_common() {
  return getRuleContexts<scsParser::Idtf_commonContext>();
}

scsParser::Idtf_commonContext* scsParser::Idtf_setContext::idtf_common(size_t i) {
  return getRuleContext<scsParser::Idtf_commonContext>(i);
}

std::vector<scsParser::Internal_sentence_listContext *> scsParser::Idtf_setContext::internal_sentence_list() {
  return getRuleContexts<scsParser::Internal_sentence_listContext>();
}

scsParser::Internal_sentence_listContext* scsParser::Idtf_setContext::internal_sentence_list(size_t i) {
  return getRuleContext<scsParser::Internal_sentence_listContext>(i);
}

std::vector<scsParser::Attr_listContext *> scsParser::Idtf_setContext::attr_list() {
  return getRuleContexts<scsParser::Attr_listContext>();
}

scsParser::Attr_listContext* scsParser::Idtf_setContext::attr_list(size_t i) {
  return getRuleContext<scsParser::Attr_listContext>(i);
}


size_t scsParser::Idtf_setContext::getRuleIndex() const {
  return scsParser::RuleIdtf_set;
}


scsParser::Idtf_setContext* scsParser::idtf_set() {
  Idtf_setContext *_localctx = _tracker.createInstance<Idtf_setContext>(_ctx, getState());
  enterRule(_localctx, 30, scsParser::RuleIdtf_set);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(scsParser::T__57);
     
            std::string const setIdtf = "..set_" + std::to_string(_localctx->start->getLine()) + "_" + std::to_string(_localctx->start->getCharPositionInLine());
            _localctx->handle = m_parser->ProcessIdentifier(setIdtf);
            ElementHandle const typeEdge = m_parser->ProcessConnector("->");
            ElementHandle const typeClass = m_parser->ProcessIdentifier("sc_node_tuple");

            m_parser->ProcessTriple(typeClass, typeEdge, _localctx->handle);
          
    setState(144);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(143);
      dynamic_cast<Idtf_setContext *>(_localctx)->a1 = attr_list();
      break;
    }

    }
    setState(146);
    dynamic_cast<Idtf_setContext *>(_localctx)->i1 = idtf_common();

            ElementHandle const edge = m_parser->ProcessConnector("->");
            m_parser->ProcessTriple(_localctx->handle, edge, _localctx->i1->handle);
            
            if (_localctx->a1 != nullptr)
            {
              APPEND_ATTRS(_localctx->a1->items, edge);
            }
          
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scsParser::T__60) {
      setState(148);
      internal_sentence_list(_localctx->i1->handle);
    }
    setState(162);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scsParser::T__58) {
      setState(151);
      match(scsParser::T__58);
      setState(153);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(152);
        dynamic_cast<Idtf_setContext *>(_localctx)->a2 = attr_list();
        break;
      }

      }
      setState(155);
      dynamic_cast<Idtf_setContext *>(_localctx)->i2 = idtf_common();

                ElementHandle const edge = m_parser->ProcessConnector("->");
                m_parser->ProcessTriple(_localctx->handle, edge, _localctx->i2->handle);
                
                if (_localctx->a2 != nullptr)
                {
                  APPEND_ATTRS(_localctx->a2->items, edge);
                }
              
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == scsParser::T__60) {
        setState(157);
        internal_sentence_list(_localctx->i2->handle);
      }
      setState(164);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(165);
    match(scsParser::T__59);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_commonContext ------------------------------------------------------------------

scsParser::Idtf_commonContext::Idtf_commonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::AliasContext* scsParser::Idtf_commonContext::alias() {
  return getRuleContext<scsParser::AliasContext>(0);
}

scsParser::Idtf_systemContext* scsParser::Idtf_commonContext::idtf_system() {
  return getRuleContext<scsParser::Idtf_systemContext>(0);
}

scsParser::Idtf_edgeContext* scsParser::Idtf_commonContext::idtf_edge() {
  return getRuleContext<scsParser::Idtf_edgeContext>(0);
}

scsParser::Idtf_setContext* scsParser::Idtf_commonContext::idtf_set() {
  return getRuleContext<scsParser::Idtf_setContext>(0);
}

scsParser::ContourContext* scsParser::Idtf_commonContext::contour() {
  return getRuleContext<scsParser::ContourContext>(0);
}

scsParser::ContentContext* scsParser::Idtf_commonContext::content() {
  return getRuleContext<scsParser::ContentContext>(0);
}

tree::TerminalNode* scsParser::Idtf_commonContext::LINK() {
  return getToken(scsParser::LINK, 0);
}


size_t scsParser::Idtf_commonContext::getRuleIndex() const {
  return scsParser::RuleIdtf_common;
}


scsParser::Idtf_commonContext* scsParser::idtf_common() {
  Idtf_commonContext *_localctx = _tracker.createInstance<Idtf_commonContext>(_ctx, getState());
  enterRule(_localctx, 32, scsParser::RuleIdtf_common);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scsParser::ALIAS_SYMBOLS: {
        enterOuterAlt(_localctx, 1);
        setState(167);
        dynamic_cast<Idtf_commonContext *>(_localctx)->a = alias();
         
              std::string const _alias = _localctx->a->getText();
              _localctx->handle = m_parser->ResolveAlias(_alias);
              if (!_localctx->handle.IsValid())
              {
                //PARSE_ERROR(_localctx->start->getLine(), _localctx->start->getCharPositionInLine(),
                  //"Can't resolve alias `" << _alias << "`. You should use assigment of alias before usage.");
              }
            
        break;
      }

      case scsParser::T__42:
      case scsParser::T__44:
      case scsParser::T__45:
      case scsParser::T__46:
      case scsParser::T__47:
      case scsParser::T__48:
      case scsParser::T__49:
      case scsParser::T__50:
      case scsParser::T__51:
      case scsParser::T__52:
      case scsParser::T__53:
      case scsParser::ID_SYSTEM: {
        enterOuterAlt(_localctx, 2);
        setState(170);
        dynamic_cast<Idtf_commonContext *>(_localctx)->is = idtf_system();
         _localctx->handle = _localctx->is->handle; 
        break;
      }

      case scsParser::T__55: {
        enterOuterAlt(_localctx, 3);
        setState(173);
        dynamic_cast<Idtf_commonContext *>(_localctx)->ie = idtf_edge();
         _localctx->handle = _localctx->ie->handle; 
        break;
      }

      case scsParser::T__57: {
        enterOuterAlt(_localctx, 4);
        setState(176);
        dynamic_cast<Idtf_commonContext *>(_localctx)->iset = idtf_set();
         _localctx->handle = _localctx->iset->handle; 
        break;
      }

      case scsParser::CONTOUR_BEGIN: {
        enterOuterAlt(_localctx, 5);
        setState(179);
        dynamic_cast<Idtf_commonContext *>(_localctx)->ct = contour();
         _localctx->handle = _localctx->ct->handle; 
        break;
      }

      case scsParser::T__0:
      case scsParser::CONTENT_BODY: {
        enterOuterAlt(_localctx, 6);
        setState(182);
        dynamic_cast<Idtf_commonContext *>(_localctx)->cn = content();
         _localctx->handle = _localctx->cn->handle; 
        break;
      }

      case scsParser::LINK: {
        enterOuterAlt(_localctx, 7);
        setState(185);
        dynamic_cast<Idtf_commonContext *>(_localctx)->linkToken = match(scsParser::LINK);

              std::string const value = dynamic_cast<Idtf_commonContext *>(_localctx)->linkToken->getText();
              //SC_ASSERT(value.size() > 1, ());
              _localctx->handle = m_parser->ProcessFileURL(value.substr(1, value.size() - 2));
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Idtf_listContext ------------------------------------------------------------------

scsParser::Idtf_listContext::Idtf_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scsParser::Idtf_commonContext *> scsParser::Idtf_listContext::idtf_common() {
  return getRuleContexts<scsParser::Idtf_commonContext>();
}

scsParser::Idtf_commonContext* scsParser::Idtf_listContext::idtf_common(size_t i) {
  return getRuleContext<scsParser::Idtf_commonContext>(i);
}

std::vector<scsParser::Internal_sentence_listContext *> scsParser::Idtf_listContext::internal_sentence_list() {
  return getRuleContexts<scsParser::Internal_sentence_listContext>();
}

scsParser::Internal_sentence_listContext* scsParser::Idtf_listContext::internal_sentence_list(size_t i) {
  return getRuleContext<scsParser::Internal_sentence_listContext>(i);
}


size_t scsParser::Idtf_listContext::getRuleIndex() const {
  return scsParser::RuleIdtf_list;
}


scsParser::Idtf_listContext* scsParser::idtf_list() {
  Idtf_listContext *_localctx = _tracker.createInstance<Idtf_listContext>(_ctx, getState());
  enterRule(_localctx, 34, scsParser::RuleIdtf_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    dynamic_cast<Idtf_listContext *>(_localctx)->i1 = idtf_common();
     _localctx->items.push_back(_localctx->i1->handle); 
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scsParser::T__60) {
      setState(191);
      internal_sentence_list(_localctx->i1->handle);
    }
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(194);
        match(scsParser::T__58);
        setState(195);
        dynamic_cast<Idtf_listContext *>(_localctx)->i2 = idtf_common();
         _localctx->items.push_back(_localctx->i2->handle); 
        setState(198);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == scsParser::T__60) {
          setState(197);
          internal_sentence_list(_localctx->i2->handle);
        } 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Internal_sentenceContext ------------------------------------------------------------------

scsParser::Internal_sentenceContext::Internal_sentenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Internal_sentenceContext::Internal_sentenceContext(ParserRuleContext *parent, size_t invokingState, ElementHandle source)
  : ParserRuleContext(parent, invokingState) {
  this->source = source;
}

scsParser::ConnectorContext* scsParser::Internal_sentenceContext::connector() {
  return getRuleContext<scsParser::ConnectorContext>(0);
}

scsParser::Idtf_listContext* scsParser::Internal_sentenceContext::idtf_list() {
  return getRuleContext<scsParser::Idtf_listContext>(0);
}

scsParser::Attr_listContext* scsParser::Internal_sentenceContext::attr_list() {
  return getRuleContext<scsParser::Attr_listContext>(0);
}

scsParser::Internal_sentence_listContext* scsParser::Internal_sentenceContext::internal_sentence_list() {
  return getRuleContext<scsParser::Internal_sentence_listContext>(0);
}


size_t scsParser::Internal_sentenceContext::getRuleIndex() const {
  return scsParser::RuleInternal_sentence;
}


scsParser::Internal_sentenceContext* scsParser::internal_sentence(ElementHandle source) {
  Internal_sentenceContext *_localctx = _tracker.createInstance<Internal_sentenceContext>(_ctx, getState(), source);
  enterRule(_localctx, 36, scsParser::RuleInternal_sentence);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scsParser::T__1:
      case scsParser::T__2:
      case scsParser::T__3:
      case scsParser::T__4:
      case scsParser::T__5:
      case scsParser::T__6:
      case scsParser::T__7:
      case scsParser::T__8:
      case scsParser::T__9:
      case scsParser::T__10:
      case scsParser::T__11:
      case scsParser::T__12:
      case scsParser::T__13:
      case scsParser::T__14:
      case scsParser::T__15:
      case scsParser::T__16:
      case scsParser::T__17:
      case scsParser::T__18:
      case scsParser::T__19:
      case scsParser::T__20:
      case scsParser::T__21:
      case scsParser::T__22:
      case scsParser::T__23:
      case scsParser::T__24:
      case scsParser::T__25:
      case scsParser::T__26:
      case scsParser::T__27:
      case scsParser::T__28:
      case scsParser::T__29:
      case scsParser::T__30:
      case scsParser::T__31:
      case scsParser::T__32:
      case scsParser::T__33:
      case scsParser::T__34:
      case scsParser::T__35:
      case scsParser::T__36:
      case scsParser::T__37:
      case scsParser::T__38:
      case scsParser::T__39:
      case scsParser::T__40: {
        enterOuterAlt(_localctx, 1);
        setState(205);
        dynamic_cast<Internal_sentenceContext *>(_localctx)->c = connector();
        setState(207);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          setState(206);
          dynamic_cast<Internal_sentenceContext *>(_localctx)->attrs = attr_list();
          break;
        }

        }
        setState(209);
        dynamic_cast<Internal_sentenceContext *>(_localctx)->targets = idtf_list();

              for (auto const & trg : _localctx->targets->items)
              {
                ElementHandle const edge = m_parser->ProcessConnector(dynamic_cast<Internal_sentenceContext *>(_localctx)->c->text);
                m_parser->ProcessTriple(source, edge, trg);
                
                if (_localctx->attrs != nullptr)
                {
                  APPEND_ATTRS(_localctx->attrs->items, edge);
                }
              }
            
        break;
      }

      case scsParser::T__60: {
        enterOuterAlt(_localctx, 2);
        setState(212);
        internal_sentence_list(source);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Internal_sentence_listContext ------------------------------------------------------------------

scsParser::Internal_sentence_listContext::Internal_sentence_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Internal_sentence_listContext::Internal_sentence_listContext(ParserRuleContext *parent, size_t invokingState, ElementHandle source)
  : ParserRuleContext(parent, invokingState) {
  this->source = source;
}

std::vector<scsParser::Internal_sentenceContext *> scsParser::Internal_sentence_listContext::internal_sentence() {
  return getRuleContexts<scsParser::Internal_sentenceContext>();
}

scsParser::Internal_sentenceContext* scsParser::Internal_sentence_listContext::internal_sentence(size_t i) {
  return getRuleContext<scsParser::Internal_sentenceContext>(i);
}


size_t scsParser::Internal_sentence_listContext::getRuleIndex() const {
  return scsParser::RuleInternal_sentence_list;
}


scsParser::Internal_sentence_listContext* scsParser::internal_sentence_list(ElementHandle source) {
  Internal_sentence_listContext *_localctx = _tracker.createInstance<Internal_sentence_listContext>(_ctx, getState(), source);
  enterRule(_localctx, 38, scsParser::RuleInternal_sentence_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(scsParser::T__60);
    setState(219); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(216);
      internal_sentence(source);
      setState(217);
      match(scsParser::T__41);
      setState(221); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scsParser::T__1)
      | (1ULL << scsParser::T__2)
      | (1ULL << scsParser::T__3)
      | (1ULL << scsParser::T__4)
      | (1ULL << scsParser::T__5)
      | (1ULL << scsParser::T__6)
      | (1ULL << scsParser::T__7)
      | (1ULL << scsParser::T__8)
      | (1ULL << scsParser::T__9)
      | (1ULL << scsParser::T__10)
      | (1ULL << scsParser::T__11)
      | (1ULL << scsParser::T__12)
      | (1ULL << scsParser::T__13)
      | (1ULL << scsParser::T__14)
      | (1ULL << scsParser::T__15)
      | (1ULL << scsParser::T__16)
      | (1ULL << scsParser::T__17)
      | (1ULL << scsParser::T__18)
      | (1ULL << scsParser::T__19)
      | (1ULL << scsParser::T__20)
      | (1ULL << scsParser::T__21)
      | (1ULL << scsParser::T__22)
      | (1ULL << scsParser::T__23)
      | (1ULL << scsParser::T__24)
      | (1ULL << scsParser::T__25)
      | (1ULL << scsParser::T__26)
      | (1ULL << scsParser::T__27)
      | (1ULL << scsParser::T__28)
      | (1ULL << scsParser::T__29)
      | (1ULL << scsParser::T__30)
      | (1ULL << scsParser::T__31)
      | (1ULL << scsParser::T__32)
      | (1ULL << scsParser::T__33)
      | (1ULL << scsParser::T__34)
      | (1ULL << scsParser::T__35)
      | (1ULL << scsParser::T__36)
      | (1ULL << scsParser::T__37)
      | (1ULL << scsParser::T__38)
      | (1ULL << scsParser::T__39)
      | (1ULL << scsParser::T__40)
      | (1ULL << scsParser::T__60))) != 0));
    setState(223);
    match(scsParser::T__61);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_lvl1Context ------------------------------------------------------------------

scsParser::Sentence_lvl1Context::Sentence_lvl1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scsParser::Idtf_lvl1Context *> scsParser::Sentence_lvl1Context::idtf_lvl1() {
  return getRuleContexts<scsParser::Idtf_lvl1Context>();
}

scsParser::Idtf_lvl1Context* scsParser::Sentence_lvl1Context::idtf_lvl1(size_t i) {
  return getRuleContext<scsParser::Idtf_lvl1Context>(i);
}


size_t scsParser::Sentence_lvl1Context::getRuleIndex() const {
  return scsParser::RuleSentence_lvl1;
}


scsParser::Sentence_lvl1Context* scsParser::sentence_lvl1() {
  Sentence_lvl1Context *_localctx = _tracker.createInstance<Sentence_lvl1Context>(_ctx, getState());
  enterRule(_localctx, 40, scsParser::RuleSentence_lvl1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    dynamic_cast<Sentence_lvl1Context *>(_localctx)->src = idtf_lvl1();
    setState(226);
    match(scsParser::T__62);
    setState(227);
    dynamic_cast<Sentence_lvl1Context *>(_localctx)->edge = idtf_lvl1();
    setState(228);
    match(scsParser::T__62);
    setState(229);
    dynamic_cast<Sentence_lvl1Context *>(_localctx)->trg = idtf_lvl1();

          m_parser->ProcessTriple(_localctx->src->handle, _localctx->edge->handle, _localctx->trg->handle);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_lvl_4_list_itemContext ------------------------------------------------------------------

scsParser::Sentence_lvl_4_list_itemContext::Sentence_lvl_4_list_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scsParser::Sentence_lvl_4_list_itemContext::Sentence_lvl_4_list_itemContext(ParserRuleContext *parent, size_t invokingState, ElementHandle source)
  : ParserRuleContext(parent, invokingState) {
  this->source = source;
}

scsParser::ConnectorContext* scsParser::Sentence_lvl_4_list_itemContext::connector() {
  return getRuleContext<scsParser::ConnectorContext>(0);
}

scsParser::Idtf_listContext* scsParser::Sentence_lvl_4_list_itemContext::idtf_list() {
  return getRuleContext<scsParser::Idtf_listContext>(0);
}

scsParser::Attr_listContext* scsParser::Sentence_lvl_4_list_itemContext::attr_list() {
  return getRuleContext<scsParser::Attr_listContext>(0);
}


size_t scsParser::Sentence_lvl_4_list_itemContext::getRuleIndex() const {
  return scsParser::RuleSentence_lvl_4_list_item;
}


scsParser::Sentence_lvl_4_list_itemContext* scsParser::sentence_lvl_4_list_item(ElementHandle source) {
  Sentence_lvl_4_list_itemContext *_localctx = _tracker.createInstance<Sentence_lvl_4_list_itemContext>(_ctx, getState(), source);
  enterRule(_localctx, 42, scsParser::RuleSentence_lvl_4_list_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    dynamic_cast<Sentence_lvl_4_list_itemContext *>(_localctx)->c = connector();
    setState(234);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(233);
      dynamic_cast<Sentence_lvl_4_list_itemContext *>(_localctx)->attrs = attr_list();
      break;
    }

    }
    setState(236);
    dynamic_cast<Sentence_lvl_4_list_itemContext *>(_localctx)->targets = idtf_list();
     
          for (auto const & t : _localctx->targets->items)
          {
              ElementHandle const edge = m_parser->ProcessConnector(dynamic_cast<Sentence_lvl_4_list_itemContext *>(_localctx)->c->text);
              m_parser->ProcessTriple(_localctx->source, edge, t);
              
              if (_localctx->attrs != nullptr)
              {
                APPEND_ATTRS(_localctx->attrs->items, edge);
              }
          }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sentence_lvl_commonContext ------------------------------------------------------------------

scsParser::Sentence_lvl_commonContext::Sentence_lvl_commonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scsParser::Sentence_lvl_4_list_itemContext *> scsParser::Sentence_lvl_commonContext::sentence_lvl_4_list_item() {
  return getRuleContexts<scsParser::Sentence_lvl_4_list_itemContext>();
}

scsParser::Sentence_lvl_4_list_itemContext* scsParser::Sentence_lvl_commonContext::sentence_lvl_4_list_item(size_t i) {
  return getRuleContext<scsParser::Sentence_lvl_4_list_itemContext>(i);
}

scsParser::Idtf_commonContext* scsParser::Sentence_lvl_commonContext::idtf_common() {
  return getRuleContext<scsParser::Idtf_commonContext>(0);
}


size_t scsParser::Sentence_lvl_commonContext::getRuleIndex() const {
  return scsParser::RuleSentence_lvl_common;
}


scsParser::Sentence_lvl_commonContext* scsParser::sentence_lvl_common() {
  Sentence_lvl_commonContext *_localctx = _tracker.createInstance<Sentence_lvl_commonContext>(_ctx, getState());
  enterRule(_localctx, 44, scsParser::RuleSentence_lvl_common);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    dynamic_cast<Sentence_lvl_commonContext *>(_localctx)->src = idtf_common();
    setState(240);
    sentence_lvl_4_list_item(_localctx->src->handle);
    setState(245);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scsParser::T__58) {
      setState(241);
      match(scsParser::T__58);
      setState(242);
      sentence_lvl_4_list_item(_localctx->src->handle);
      setState(247);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_listContext ------------------------------------------------------------------

scsParser::Attr_listContext::Attr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> scsParser::Attr_listContext::ID_SYSTEM() {
  return getTokens(scsParser::ID_SYSTEM);
}

tree::TerminalNode* scsParser::Attr_listContext::ID_SYSTEM(size_t i) {
  return getToken(scsParser::ID_SYSTEM, i);
}

std::vector<tree::TerminalNode *> scsParser::Attr_listContext::EDGE_ATTR() {
  return getTokens(scsParser::EDGE_ATTR);
}

tree::TerminalNode* scsParser::Attr_listContext::EDGE_ATTR(size_t i) {
  return getToken(scsParser::EDGE_ATTR, i);
}


size_t scsParser::Attr_listContext::getRuleIndex() const {
  return scsParser::RuleAttr_list;
}


scsParser::Attr_listContext* scsParser::attr_list() {
  Attr_listContext *_localctx = _tracker.createInstance<Attr_listContext>(_ctx, getState());
  enterRule(_localctx, 46, scsParser::RuleAttr_list);
   dynamic_cast<Attr_listContext *>(_localctx)->items =  {}; 

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(251); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(248);
              dynamic_cast<Attr_listContext *>(_localctx)->id_systemToken = match(scsParser::ID_SYSTEM);
              setState(249);
              dynamic_cast<Attr_listContext *>(_localctx)->edge_attrToken = match(scsParser::EDGE_ATTR);

                      _localctx->items.emplace_back(m_parser->ProcessIdentifier(dynamic_cast<Attr_listContext *>(_localctx)->id_systemToken->getText()),
                                               scs::TypeResolver::IsEdgeAttrConst(dynamic_cast<Attr_listContext *>(_localctx)->edge_attrToken->getText()));
                    
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(253); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool scsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return contourSempred(dynamic_cast<ContourContext *>(context), predicateIndex);
    case 2: return contourWithJoinSempred(dynamic_cast<ContourWithJoinContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool scsParser::contourSempred(ContourContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return  _localctx->count > 0 ;

  default:
    break;
  }
  return true;
}

bool scsParser::contourWithJoinSempred(ContourWithJoinContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return  _localctx->count > 0 ;

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> scsParser::_decisionToDFA;
atn::PredictionContextCache scsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN scsParser::_atn;
std::vector<uint16_t> scsParser::_serializedATN;

std::vector<std::string> scsParser::_ruleNames = {
  "content", "contour", "contourWithJoin", "connector", "syntax", "sentence_wrap", 
  "sentence", "alias", "idtf_system", "sentence_assign", "sentence_assign_contour", 
  "idtf_lvl1_preffix", "idtf_lvl1_value", "idtf_lvl1", "idtf_edge", "idtf_set", 
  "idtf_common", "idtf_list", "internal_sentence", "internal_sentence_list", 
  "sentence_lvl1", "sentence_lvl_4_list_item", "sentence_lvl_common", "attr_list"
};

std::vector<std::string> scsParser::_literalNames = {
  "", "'_'", "'<>'", "'>'", "'<'", "'..>'", "'<..'", "'->'", "'<-'", "'<=>'", 
  "'=>'", "'<='", "'-|>'", "'<|-'", "'-/>'", "'</-'", "'~>'", "'<~'", "'~|>'", 
  "'<|~'", "'~/>'", "'</~'", "'_<>'", "'_>'", "'_<'", "'_..>'", "'_<..'", 
  "'_->'", "'_<-'", "'_<=>'", "'_=>'", "'_<='", "'_-|>'", "'_<|-'", "'_-/>'", 
  "'_</-'", "'_~>'", "'_<~'", "'_~|>'", "'_<|~'", "'_~/>'", "'_</~'", "';;'", 
  "'...'", "'='", "'sc_node'", "'sc_link'", "'sc_edge_dcommon'", "'sc_edge_ucommon'", 
  "'sc_edge_main'", "'sc_edge_access'", "'sc_arc_common'", "'sc_edge'", 
  "'sc_arc_main'", "'sc_arc_access'", "'#'", "'('", "')'", "'{'", "';'", 
  "'}'", "'(*'", "'*)'", "'|'", "", "", "'[*'", "'*]'"
};

std::vector<std::string> scsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "ID_SYSTEM", "ALIAS_SYMBOLS", 
  "CONTOUR_BEGIN", "CONTOUR_END", "CONTENT_BODY", "LINK", "EDGE_ATTR", "LINE_TERMINATOR", 
  "LINE_COMMENT", "MULTINE_COMMENT", "WS"
};

dfa::Vocabulary scsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> scsParser::_tokenNames;

scsParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4c, 0x102, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x35, 0xa, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x3e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x4a, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x4d, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x7, 0x6, 0x56, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x59, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x64, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x6f, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x8a, 0xa, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x93, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x98, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x9c, 0xa, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa1, 0xa, 0x11, 0x7, 0x11, 0xa3, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xa6, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0xbe, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0xc3, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0xc9, 0xa, 0x13, 0x7, 0x13, 0xcb, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0xce, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xd2, 0xa, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xd8, 0xa, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x6, 0x15, 0xde, 0xa, 0x15, 0xd, 
    0x15, 0xe, 0x15, 0xdf, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0xed, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xf6, 0xa, 0x18, 0xc, 0x18, 
    0xe, 0x18, 0xf9, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 
    0xfe, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0xff, 0x3, 0x19, 0x2, 0x2, 0x1a, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x2, 
    0x4, 0x3, 0x2, 0x4, 0x2b, 0x3, 0x2, 0x2f, 0x38, 0x2, 0x107, 0x2, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x63, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x75, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x85, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x24, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 
    0x3, 0x2, 0x2, 0x33, 0x35, 0x8, 0x2, 0x1, 0x2, 0x34, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x7, 0x46, 0x2, 0x2, 0x37, 0x38, 0x8, 0x2, 0x1, 0x2, 
    0x38, 0x3, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x44, 0x2, 0x2, 0x3a, 
    0x3b, 0x8, 0x3, 0x1, 0x2, 0x3b, 0x3f, 0x6, 0x3, 0x2, 0x3, 0x3c, 0x3e, 
    0x5, 0xc, 0x7, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x43, 0x7, 0x45, 0x2, 0x2, 0x43, 0x44, 0x8, 0x3, 0x1, 0x2, 
    0x44, 0x5, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x44, 0x2, 0x2, 0x46, 
    0x47, 0x8, 0x4, 0x1, 0x2, 0x47, 0x4b, 0x6, 0x4, 0x3, 0x3, 0x48, 0x4a, 
    0x5, 0xc, 0x7, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x7, 0x45, 0x2, 0x2, 0x4f, 0x50, 0x8, 0x4, 0x1, 0x2, 
    0x50, 0x7, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x9, 0x2, 0x2, 0x2, 0x52, 
    0x53, 0x8, 0x5, 0x1, 0x2, 0x53, 0x9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 
    0x5, 0xc, 0x7, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x7, 0x2, 0x2, 0x3, 0x5b, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5d, 0x5, 0xe, 0x8, 0x2, 0x5d, 0x5e, 0x7, 0x2c, 0x2, 0x2, 0x5e, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x64, 0x5, 0x2a, 0x16, 0x2, 0x60, 0x64, 
    0x5, 0x14, 0xb, 0x2, 0x61, 0x64, 0x5, 0x16, 0xc, 0x2, 0x62, 0x64, 0x5, 
    0x2e, 0x18, 0x2, 0x63, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x63, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0xf, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x43, 0x2, 0x2, 
    0x66, 0x11, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x42, 0x2, 0x2, 0x68, 
    0x6f, 0x8, 0xa, 0x1, 0x2, 0x69, 0x6a, 0x7, 0x2d, 0x2, 0x2, 0x6a, 0x6f, 
    0x8, 0xa, 0x1, 0x2, 0x6b, 0x6c, 0x5, 0x18, 0xd, 0x2, 0x6c, 0x6d, 0x8, 
    0xa, 0x1, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0x10, 0x9, 0x2, 
    0x71, 0x72, 0x7, 0x2e, 0x2, 0x2, 0x72, 0x73, 0x5, 0x22, 0x12, 0x2, 0x73, 
    0x74, 0x8, 0xb, 0x1, 0x2, 0x74, 0x15, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x5, 0x22, 0x12, 0x2, 0x76, 0x77, 0x7, 0x2e, 0x2, 0x2, 0x77, 0x78, 0x5, 
    0x6, 0x4, 0x2, 0x78, 0x79, 0x8, 0xc, 0x1, 0x2, 0x79, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x9, 0x3, 0x2, 0x2, 0x7b, 0x7c, 0x8, 0xd, 0x1, 
    0x2, 0x7c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x18, 0xd, 0x2, 
    0x7e, 0x7f, 0x7, 0x39, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x42, 0x2, 0x2, 0x80, 
    0x81, 0x8, 0xe, 0x1, 0x2, 0x81, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x5, 0x1a, 0xe, 0x2, 0x83, 0x84, 0x8, 0xf, 0x1, 0x2, 0x84, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x3a, 0x2, 0x2, 0x86, 0x87, 0x5, 0x22, 
    0x12, 0x2, 0x87, 0x89, 0x5, 0x8, 0x5, 0x2, 0x88, 0x8a, 0x5, 0x30, 0x19, 
    0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x22, 0x12, 0x2, 0x8c, 
    0x8d, 0x7, 0x3b, 0x2, 0x2, 0x8d, 0x8e, 0x8, 0x10, 0x1, 0x2, 0x8e, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x3c, 0x2, 0x2, 0x90, 0x92, 0x8, 
    0x11, 0x1, 0x2, 0x91, 0x93, 0x5, 0x30, 0x19, 0x2, 0x92, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x95, 0x5, 0x22, 0x12, 0x2, 0x95, 0x97, 0x8, 0x11, 0x1, 0x2, 
    0x96, 0x98, 0x5, 0x28, 0x15, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 
    0x7, 0x3d, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x30, 0x19, 0x2, 0x9b, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x9e, 0x5, 0x22, 0x12, 0x2, 0x9e, 0xa0, 0x8, 0x11, 0x1, 
    0x2, 0x9f, 0xa1, 0x5, 0x28, 0x15, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x3e, 
    0x2, 0x2, 0xa8, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x10, 0x9, 
    0x2, 0xaa, 0xab, 0x8, 0x12, 0x1, 0x2, 0xab, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xad, 0x5, 0x12, 0xa, 0x2, 0xad, 0xae, 0x8, 0x12, 0x1, 0x2, 0xae, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x1e, 0x10, 0x2, 0xb0, 0xb1, 
    0x8, 0x12, 0x1, 0x2, 0xb1, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x5, 
    0x20, 0x11, 0x2, 0xb3, 0xb4, 0x8, 0x12, 0x1, 0x2, 0xb4, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb6, 0x5, 0x4, 0x3, 0x2, 0xb6, 0xb7, 0x8, 0x12, 0x1, 
    0x2, 0xb7, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x2, 0x2, 0x2, 
    0xb9, 0xba, 0x8, 0x12, 0x1, 0x2, 0xba, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0x47, 0x2, 0x2, 0xbc, 0xbe, 0x8, 0x12, 0x1, 0x2, 0xbd, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xac, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0x23, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x22, 0x12, 0x2, 
    0xc0, 0xc2, 0x8, 0x13, 0x1, 0x2, 0xc1, 0xc3, 0x5, 0x28, 0x15, 0x2, 0xc2, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x3d, 0x2, 0x2, 0xc5, 0xc6, 0x5, 
    0x22, 0x12, 0x2, 0xc6, 0xc8, 0x8, 0x13, 0x1, 0x2, 0xc7, 0xc9, 0x5, 0x28, 
    0x15, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x25, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xd1, 0x5, 0x8, 0x5, 0x2, 0xd0, 0xd2, 0x5, 
    0x30, 0x19, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x24, 0x13, 
    0x2, 0xd4, 0xd5, 0x8, 0x14, 0x1, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd8, 0x5, 0x28, 0x15, 0x2, 0xd7, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdd, 
    0x7, 0x3f, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x26, 0x14, 0x2, 0xdb, 0xdc, 0x7, 
    0x2c, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xe2, 0x7, 0x40, 0x2, 0x2, 0xe2, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe4, 0x5, 0x1c, 0xf, 0x2, 0xe4, 0xe5, 0x7, 0x41, 0x2, 0x2, 0xe5, 0xe6, 
    0x5, 0x1c, 0xf, 0x2, 0xe6, 0xe7, 0x7, 0x41, 0x2, 0x2, 0xe7, 0xe8, 0x5, 
    0x1c, 0xf, 0x2, 0xe8, 0xe9, 0x8, 0x16, 0x1, 0x2, 0xe9, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xec, 0x5, 0x8, 0x5, 0x2, 0xeb, 0xed, 0x5, 0x30, 0x19, 
    0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x5, 0x24, 0x13, 0x2, 0xef, 
    0xf0, 0x8, 0x17, 0x1, 0x2, 0xf0, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 
    0x5, 0x22, 0x12, 0x2, 0xf2, 0xf7, 0x5, 0x2c, 0x17, 0x2, 0xf3, 0xf4, 
    0x7, 0x3d, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x2c, 0x17, 0x2, 0xf5, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x42, 0x2, 0x2, 
    0xfb, 0xfc, 0x7, 0x48, 0x2, 0x2, 0xfc, 0xfe, 0x8, 0x19, 0x1, 0x2, 0xfd, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x34, 0x3f, 0x4b, 0x57, 0x63, 0x6e, 0x89, 0x92, 
    0x97, 0x9b, 0xa0, 0xa4, 0xbd, 0xc2, 0xc8, 0xcc, 0xd1, 0xd7, 0xdf, 0xec, 
    0xf7, 0xff, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

scsParser::Initializer scsParser::_init;
