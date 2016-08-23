#include "UT_SerialComm.h"
#define UT_TRACE
#ifdef UT_TRACE
#include "Logfile.h"
#endif


UT_SerialComm::UT_SerialComm()
{

}

UT_SerialComm::~UT_SerialComm()
{

}


void UT_SerialComm::setUp()
{

}
void UT_SerialComm::tearDown()
{

}


void UT_SerialComm::set_run_Serial()
{
	printf("\n Entry set_run_Serial");

	this->app.HMIInit();
	this->app.HMITask();
	
	uint8_t qbuffer[] = { 00, 15, 01, 15, 00, 00, 00, 00 };
	uint8_t result;

	//serialCommLayer->get_ODISerial()->Appl_SrlQueueComError(0);

	//serialCommLayer->get_ODISerial()->SrlQueue_ClearRxQueue();
	
//	serialCommLayer->getODISerial()->Appl_SrlQueueComError(0);
//	serialCommLayer->getODISerial()->SrlQueue_ClearRxQueue();
//	serialCommLayer->getODISerial()->SrlQueue_ClearTxQueue();
//	result = serialCommLayer->getODISerial()->SrlQueue_GetComStatus();
//	serialCommLayer->getODISerial()->SrlQueue_GetMsg(qbuffer);
////	serialCommLayer->getODISerial()->SrlQueue_ImmediateSendMsg(qbuffer, 6);
//	serialCommLayer->getODISerial()->SrlQueue_IsRxMsgAvail();
//	serialCommLayer->getODISerial()->SrlQueue_ReInitSerialCom();
//	//serialCommLayer->getODISerial()->SrlQueue_SendMsg(qbuffer, 5);
	serialCommLayer->getODIMsg()->getItsIODIProxy();
	serialCommLayer->getODISerial();
	serialCommLayer->getODIMsg();
	serialCommLayerNew.getODIMsg()->ProcessTxQ();
//	serialCommLayer->get_ODISerial()->Appl_SrlQueueComError(1);
//	serialCommLayer->getWriteStatus();
//	serialCommLayer->setWriteStatus(ODI_WRITE_STATUS_SUCCESS);
	serialCommLayerNew.SrlQueue_ClearRxQueue();
	serialCommLayerNew.Appl_SrlQueueComError(0);
	serialCommLayerNew.Appl_SrlQueueComError(1);
	serialCommLayerNew.SrlQueue_ClearTxQueue();
	serialCommLayerNew.SrlQueue_GetComStatus();
	serialCommLayerNew.SrlQueue_GetMsg(qbuffer);
	serialCommLayerNew.SrlQueue_ImmediateSendMsg(qbuffer, 6);
//	result = serialCommLayerNew.SrlQueue_IsRxMsgAvail();
	serialCommLayerNew.SrlQueue_ReInitSerialCom();
	serialCommLayerNew.SrlQueue_SendMsg(qbuffer, 5);
	serialCommLayerNew.getODISerial()->Appl_SrlQueueComError(0);
	serialCommLayerNew.getODISerial()->SrlQueue_ClearRxQueue();
	serialCommLayerNew.getODISerial()->SrlQueue_ClearTxQueue();
	serialCommLayerNew.getODISerial()->SrlQueue_GetComStatus();
	serialCommLayerNew.getODISerial()->SrlQueue_GetMsg(qbuffer);
	serialCommLayerNew.getODISerial()->SrlQueue_ImmediateSendMsg(qbuffer, 6);
	serialCommLayerNew.getODISerial()->SrlQueue_IsRxMsgAvail();
	serialCommLayerNew.getODISerial()->SrlQueue_ReInitSerialCom();
	serialCommLayerNew.getODISerial()->SrlQueue_SendMsg(qbuffer, 5);
//	serialCommLayerNew1->getODISerial()->SrlQueue_ClearRxQueue();
	set_run_Appl_SrlQueueComError();
	printf("set_run_Appl_SrlQueueComError done\n ");

	set_run_getcommStatus();
	printf("set_run_getcommStatus done\n ");

	set_run_Ismsgavail();
	printf("set_run_Ismsgavail done\n ");

	set_run_NoArgumentMethods();
	printf("set_run_NoArgumentMethods done \n ");

	set_run_SrlQueue_ImmediateSendMsg();
	printf("set_run_SrlQueue_ImmediateSendMsg done \n ");

	set_run_SrlQueue_SendMsg();
	printf("set_run_SrlQueue_SendMsg done\n ");
	
	set_run_SrlQueue_GetMsg();
	printf("set_run_SrlQueue_GetMsg done\n ");



}

void UT_SerialComm::set_run_Appl_SrlQueueComError()
{
	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_1
	* In Parameter	@Commstatus: COM_STATUS_NO_ERROR_COMM_ACTIVE									*
	*				@Code to be Covered: case COM_STATUS_NO_ERROR_COMM_ACTIVE is executed			*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	//ODI Subscription
	uint8_t buff[] = { 00, 15, 01, 15, 00, 00, 00, 00 }; 
	
	serialCommLayerStub.setSrlQueue_GetMsg(buff);
//	printf("\n ODI_UN_TC_Appl_1");	
	serialCommLayerStub.setAppl_SrlQueueComError(0);
	printf("\n setAppl_SrlQueueComError end");
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());
	

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_2
	* In Parameter	@Commstatus: COM_STATUS_COMM_ACTIVE												*
	*				@Code to be Covered: case COM_STATUS_COMM_ACTIVE is executed					*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	
//	printf("\n ODI_UN_TC_Appl_2");
	
	serialCommLayerStub.setAppl_SrlQueueComError(1);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_3
	* In Parameter	@Commstatus: COM_STATUS_NOT_INIT												*
	*				@Code to be Covered: case COM_STATUS_NOT_INIT is executed						*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/

//	printf("\n ODI_UN_TC_Appl_3");

	serialCommLayerStub.setAppl_SrlQueueComError(2);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_4
	* In Parameter	@Commstatus: COM_STATUS_TX_ERROR												*
	*				@Code to be Covered: case COM_STATUS_TX_ERROR is executed						*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/

//	printf("\n ODI_UN_TC_Appl_4");

	serialCommLayerStub.setAppl_SrlQueueComError(3);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_5
	* In Parameter	@Commstatus: COM_STATUS_RX_ERROR												*
	*				@Code to be Covered: case COM_STATUS_RX_ERROR is executed						*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	
//	printf("\n ODI_UN_TC_Appl_5");
	
	serialCommLayerStub.setAppl_SrlQueueComError(4);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_6
	* In Parameter	@Commstatus: COM_STATUS_TXRX_ERROR												*
	*				@Code to be Covered: case COM_STATUS_TXRX_ERROR is executed						*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	
//	printf("\n ODI_UN_TC_Appl_6");
	
	serialCommLayerStub.setAppl_SrlQueueComError(5);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_7
	* In Parameter	@Commstatus: COM_STATUS_RXBUF_OVERWRITE											*
	*				@Code to be Covered: case COM_STATUS_RXBUF_OVERWRITE is executed				*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	
//	printf("\n ODI_UN_TC_Appl_7");
	
	serialCommLayerStub.setAppl_SrlQueueComError(6);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	/************************Appl_SrlQueueComError **************************************************
	* Test Case ID  ODI_UN_TC_Appl_8
	* In Parameter	@Commstatus: Comm_Error															*
	*				@Code to be Covered: default case  is executed									*
	* Out Parameter @Result - clear Rx and Tx queue													*
	*************************************************************************************************/
	
//	printf("\n ODI_UN_TC_Appl_8");
	
	serialCommLayerStub.setAppl_SrlQueueComError(7);
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->Appl_SrlQueueComError(serialCommLayerStub.getAppl_SrlQueueComError());

	printf("Exit set_run_Appl_SrlQueueComError");

}

void UT_SerialComm::set_run_SrlQueue_GetMsg()
{
	//ODI Subscription
	uint8_t buff7[] = { 00, 15, 01, 15, 00, 00, 00, 00 };
	//ODI Action
	uint8_t buff8[] = { 00, 176, 01, 01, 15, 00, 00, 00 };
	//ODI UnSubscription
	uint8_t buff9[] = { 00, 15, 01, 9, 00, 00, 00, 00, 00, 00 };

	uint16 readSize = 0;
	uint16 Ret = 8;
	uint16 Ret2 = 10;
	uint16 Ret3 = 0;

	/************************SrlQueue_GetMsg ************************************
	* Test Case ID  ODI_UN_TC_GETMSG_01
	* In Parameter	@buffer = buff7[] = { 00, 15, 01, 15, 00, 00, 00, 00 }	    *
	*				@Code to be Covered: Reads the message from the queue		*
	* Out Parameter  @Result - 	readsize									    *
	*****************************************************************************/
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearRxQueue();
	app.getItsCSystemProxy()->getItsCODIProxy()->PostRxQ(8, buff7);
	
//	printf("\n ODI_UN_TC_GETMSG_01");
	
	serialCommLayerStub.setSrlQueue_GetMsg(buff7);
	readSize = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_GetMsg(serialCommLayerStub.getSrlQueue_GetMsg());
	printf("tjhe value of readsize is :%d", readSize);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_GETMSG_01 : The size of the message in the RxQueue", Ret, readSize);

	/************************SrlQueue_GetMsg ************************************
	* Test Case ID  ODI_UN_TC_GETMSG_02
	* In Parameter	@buffer = buff8[] = { 00, 176, 01, 01, 15, 00, 00, 00 }	    *
	*				@Code to be Covered: Reads the message from the queue		*
	* Out Parameter  @Result - 	readsize									    *
	*****************************************************************************/
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearRxQueue();
	app.getItsCSystemProxy()->getItsCODIProxy()->PostRxQ(10, buff9);
	
//	printf("\n ODI_UN_TC_GETMSG_02");
	
	serialCommLayerStub.setSrlQueue_GetMsg(buff9);
	readSize = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_GetMsg(serialCommLayerStub.getSrlQueue_GetMsg());
	printf("tjhe value of readsize is :%d", readSize);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_GETMSG_02 : The size of the message in the RxQueue", Ret2, readSize);

	/************************SrlQueue_GetMsg *************************************
	* Test Case ID  ODI_UN_TC_GETMSG_03
	* In Parameter	@buffer = buff9[] ={ 00, 15, 01, 9, 00, 00, 00, 00, 00, 00 } *
	*				@Code to be Covered: Reads the message from the queue		 *
	* Out Parameter  @Result - 	readsize									     *
	******************************************************************************/
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearRxQueue();
	
	printf("\n ODI_UN_TC_GETMSG_03");
	
	serialCommLayerStub.setSrlQueue_GetMsg(buff9);
	readSize = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_GetMsg(serialCommLayerStub.getSrlQueue_GetMsg());
	printf("tjhe value of readsize is :%d", readSize);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_GETMSG_03 : The size of the message in the RxQueue", Ret3, readSize);
}


void UT_SerialComm::set_run_getcommStatus()
{
	/************************SrlQueue_GetComStatus********************************
	* Test Case ID  ODI_UN_TC_GETCOMM_01
	*				@Code to be Covered: application gives the error status		 *
	* Out Parameter  @Result - 	CommErrorStatus								     *
	******************************************************************************/
	
//	printf("\n ODI_UN_TC_GETCOMM_01");

	uint8_t retval = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_GetComStatus();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_GETCOMM_01 : The Error status is", (uint8_t)0, retval);
}

void UT_SerialComm::set_run_Ismsgavail()
{
	/************************SrlQueue_IsRxMsgAvail********************************
	* Test Case ID  ODI_UN_TC_ISRX_01														
	*				@Code to be Covered: Number of messages are read in the queue*
	* Out Parameter  @Result - 	NumberOfmsgs								     *
	******************************************************************************/

	printf("\n ODI_UN_TC_ISRX_01");

	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearRxQueue();
	uint8_t retval = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_IsRxMsgAvail();
	printf("THe value is retval :%d", retval);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_ISRX_01 : The number of messages in the Rxqueue", (uint8_t)0, retval);
}
void UT_SerialComm::set_run_NoArgumentMethods()
{
	
	
	/************************SrlQueue_ClearRxQueue********************************
	* Test Case ID  ODI_UN_TC_CLEARRX_01																			
	*				@Code to be Covered: clears the Rx queue					 *
	* Out Parameter  @Result - 	void function								     *
	******************************************************************************/

//	printf("\n ODI_UN_TC_CLEARRX_01");
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearRxQueue();

	/************************SrlQueue_ClearTxQueue********************************
	* Test Case ID  ODI_UN_TC_CLEARTX_01																		
	*				@Code to be Covered: clears the Tx queue					 *
	* Out Parameter  @Result - 	void function								     *
	******************************************************************************/
	
//	printf("\n ODI_UN_TC_CLEARTX_01");
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ClearTxQueue();

	/************************SrlQueue_ReInitSerialCom*****************************
	* Test Case ID  ODI_UN_TC_REINIT_01																		
	*				@Code to be Covered: clears the  queue						 *
	* Out Parameter  @Result - 	void function								     *
	******************************************************************************/

//	printf("\n ODI_UN_TC_REINIT_01");
	app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ReInitSerialCom();
}

void UT_SerialComm::set_run_SrlQueue_ImmediateSendMsg()
{
	//PRNDL_MESSAGE
	uint8_t buff1[] = { 238, 5, 3 };


	//ODIQUEUE_MSG_EVENT
	uint8_t buff2[] = { 1, 0, 191, 2 };


	//ODI_MSG_DYN_DATA
	uint8_t buff4[] = { 3, 0, 0, 4, 3, 0, 0, 0, 0, 0 };


	//ODI_MSG_TPDYN_STRING_DATA
	uint8_t buff5[] = { 9, 0, 18, 2, 11, 0, 11, 0, 6, 23, 23, 23, 23, 23, 23 };

	//Invalid Message
	uint8_t buff6[] = { 10, 00, 00, 00, 24, 00, 00, 00, 00 };

	uint8_t status = 0;

	/************************SrlQueue_ImmediateSendMsg **************************
	* Test Case ID  ODI_UN_TC_IMMSEND_01
	* In Parameter	@buffer = buff1[] = { 238, 3, 5 }							*
	*				@bufsize = 54												*
	*				@ImmSend = 1												*
	*				@Code to be Covered: The message will be processed			*
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS						    *
	*****************************************************************************/

//	printf("\n ODI_UN_TC_IMMSEND_01");

	serialCommLayerStub.setSrlQueue_ImmediateSendMsg(buff1,54);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ImmediateSendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	printf("The value of Immsend is :%d",status);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Checking the Imm Send ODI Deserilize Return Value for (PRNDL message)", uint8_t(0), status);

	/************************SrlQueue_ImmediateSendMsg **************************
	* Test Case ID  ODI_UN_TC_IMMSEND_02
	* In Parameter	@buffer =  buff2[] = { 1, 0, 1, 4 }							*
	*				@bufsize = 300												*
	*				@ImmSend = 1												*
	*				@Code to be Covered: The message will be processed			*
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS						    *
	*****************************************************************************/

//	printf("\n ODI_UN_TC_IMMSEND_02");

	serialCommLayerStub.setSrlQueue_ImmediateSendMsg(buff2, 300);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ImmediateSendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	printf("The value of Immsend is :%d", status);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Checking the Imm Send ODI Deserilize Return Value for (Event message)", uint8_t(0), status);



	/************************SrlQueue_ImmediateSendMsg ***************************************
	* Test Case ID  ODI_UN_TC_IMMSEND_03
	* In Parameter	@buffer = buff3[] = { 2, 0, 8, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0 }	 *
	*				@bufsize = 43															 *
	*				@ImmSend = 1															 *
	*				@Code to be Covered: The message will be processed						 *
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS										 *
	******************************************************************************************/

//	printf("\n ODI_UN_TC_IMMSEND_03");

	serialCommLayerStub.setSrlQueue_ImmediateSendMsg(buff2, 43);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_ImmediateSendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	printf("The value of Immsend is :%d", status);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Checking the Imm Send ODI Deserilize Return Value for (Indication message)", uint8_t(0), status);



}

void UT_SerialComm::set_run_SrlQueue_SendMsg()
{

	//PRNDL_MESSAGE
	uint8_t buff1[] = { 238, 5, 3 };


	//ODIQUEUE_MSG_EVENT
	uint8_t buff2[] = { 1, 0, 191, 2 };

	//ODI_MSG_INDICATION
	uint8_t buff3[] = { 2, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


	//ODI_MSG_DYN_DATA
	uint8_t buff4[] = { 3, 0, 0, 4, 3, 0, 0, 0, 0, 0 };


	//ODI_MSG_TPDYN_STRING_DATA
	uint8_t buff5[] = { 9, 0, 18, 2, 11, 0, 11, 0, 6, 23, 23, 23, 23, 23, 23 };

	//Invalid Message
	uint8_t buff6[] = { 10, 00, 00, 00, 24, 00, 00, 00, 00 };

	uint8_t status = 0;

	/************************SrlQueue_SendMsg ***********************************
	* Test Case ID  ODI_UN_TC_SNDMSG_01
	* In Parameter	@buffer = buff1[] = { 238, 3, 5 }							*
	*				@bufsize = 54												*
	*				@ImmSend = 1												*
	*				@Code to be Covered: The message will be processed			*
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS						    *
	*****************************************************************************/
	
	printf("\n ODI_UN_TC_SNDMSG_01");

	serialCommLayerStub.setSrlQueue_SendMsg(buff1, 3);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_01 : Checking the Imm Send ODI Deserilize Return Value for (PRNDL message)", uint8_t(0), status);

	/************************SrlQueue_SendMsg ***********************************
	* Test Case ID  ODI_UN_TC_SNDMSG_02
	* In Parameter	@buffer =  buff2[] = { 1, 0, 1, 4 }							*
	*				@bufsize = 300												*
	*				@ImmSend = 1												*
	*				@Code to be Covered: The message will be processed			*
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS						    *
	*****************************************************************************/

//	printf("\n ODI_UN_TC_SNDMSG_02");

	serialCommLayerStub.setSrlQueue_SendMsg(buff2, 300);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_02 : Checking the Imm Send ODI Deserilize Return Value for (Event message)", uint8_t(0), status);



	/************************SrlQueue_SendMsg ************************************************
	* Test Case ID  ODI_UN_TC_SNDMSG_03
	* In Parameter	@buffer = buff3[] = { 2, 0, 8, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0 }	 *
	*				@bufsize = 43															 *
	*				@ImmSend = 1															 *
	*				@Code to be Covered: The message will be processed						 *
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS										 *
	******************************************************************************************/

	printf("\n ODI_UN_TC_SNDMSG_03");

	serialCommLayerStub.setSrlQueue_SendMsg(buff3, 43);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_03 : Checking the Imm Send ODI Deserilize Return Value for (Indication message)", uint8_t(0), status);


	/************************SrlQueue_SendMsg ************************************************
	* Test Case ID  ODI_UN_TC_SNDMSG_04
	* In Parameter	@buffer = buff4[] = { 3, 0, 0, 4, 3, 0, 0, 0, 0, 0 }					 *
	*				@bufsize = 256															 *
	*				@ImmSend = 1															 *
	*				@Code to be Covered: The message will be processed						 *
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS										 *
	******************************************************************************************/

//	printf("\n ODI_UN_TC_SNDMSG_04");

	serialCommLayerStub.setSrlQueue_SendMsg(buff4, 256);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_04 : Checking the Imm Send ODI Deserilize Return Value for (Dynamicdata message)", uint8_t(0), status);

	/************************SrlQueue_SendMsg ******************************************************
	* Test Case ID  ODI_UN_TC_SNDMSG_05
	* In Parameter	@buffer = buff5[] = { 9, 0, 18, 2, 11, 0, 11, 0, 6, 23, 23, 23, 23, 23, 23 }   *
	*				@bufsize = 100																   *
	*				@ImmSend = 1																   *
	*				@Code to be Covered: The message will be processed							   *
	* Out Parameter  @Result - ODI_WRITE_STATUS_SUCCESS											   *
	************************************************************************************************/

//	printf("\n ODI_UN_TC_SNDMSG_05");

	serialCommLayerStub.setSrlQueue_SendMsg(buff5, 100);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_05 : Checking the Imm Send ODI Deserilize Return Value for (Dynamicstringdata message)", uint8_t(0), status);

	/************************SrlQueue_SendMsg ******************************************************
	* Test Case ID  ODI_UN_TC_SNDMSG_06
	* In Parameter	@buffer = buff6[] = { 10, 00, 00, 00, 24, 00, 00, 00, 00 }					   *
	*				@bufsize = 100																   *
	*				@ImmSend = 1																   *
	*				@Code to be Covered: The message cannot be be processed						   *
	* Out Parameter  @Result - ODI_WRITE_STATUS_FAIL											   *
	************************************************************************************************/

//	printf("\n ODI_UN_TC_SNDMSG_06");

	serialCommLayerStub.setSrlQueue_SendMsg(NULL, 0);
	status = app.getItsCSystemProxy()->getItsCSerialCommLayer()->SrlQueue_SendMsg(serialCommLayerStub.getbuffer(), serialCommLayerStub.getbufsize());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("ODI_UN_TC_SNDMSG_06 : Checking the Imm Send ODI Deserilize Return Value for (Unknown message)", uint8_t(1), status);



}