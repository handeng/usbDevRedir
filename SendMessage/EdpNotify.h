#ifndef __EDP_NOTIFY_H__2014_12_03__
#define __EDP_NOTIFY_H__2014_12_03__

#define EDP_NOTIFY_ID			10
#define U_DISK_INSERT			1
#define U_DISK_PULL_OUT			2

#pragma pack(1)
typedef struct _tagUDiskInfo
{
	// �ṹ��汾��
	// ��ǰ�汾: 0
	long    lVer;

	// �������
	char*    lpszPhysicsVolume;

	// �߼�����
	char*    lpszLogicVolume;

	// ��������
	char*    lpszSymbolicLink;
	
	// �̷�
	char     cDrv;
	
	// sessionId
	long     lSId;
	
	// ��ǰ��¼�û���
	char    ucName[ MAX_PATH ];
	
	// ����/�γ�
	// 1:���� 2:�γ�
	ULONG            ulAction;
    
	// ����Ӳ�̺�
	char DrvPhysicsNum[ MAX_PATH ];
    
	// Ӳ������
	// 1:�ƶ����� 2:����
	int  nDrvType;   

	// ��չ����1
	unsigned char    ucReserved1[ 128 ];

	// ��չ����2
	unsigned char    ucReserved2[ 128 ];

	// ��չ����3
	unsigned char    ucReserved3[ 128 ];


}UDISK_INFO, *LP_UDISK_INFO;
#pragma pack()

#define    LENGTH_UDISK_INFO    sizeof( UDISK_INFO )



class IEdpNotify
{
public:
	/*
	*
	*	AddRef		�������ü���
	*				����ֵ����ǰ���ü���
	*
	*/

	virtual LONG AddRef() = 0;
	
	/*
	*
	*	Release		�������ü������ü��� = 0 �ͷŶ���
	*				����ֵ����ǰ���ü���
	*
	*/

	virtual LONG Release() = 0;
	
	/*
	*
	*	Initialize	�����ʼ��
	*				����ֵ��TRUE �ɹ� FALSE ʧ��
	*
	*/

	virtual BOOL Initialize() = 0;
	
	/*
	*
	*	Terminate	������ֹ���ڽ����˳�ʱ����
	*				����ֵ����
	*
	*/

	virtual void Terminate() = 0;


	/*
		* Parameter(s)  : 
		* Description   : U�̲���/�γ�ʱ֪ͨ
		* Return        : �ɹ�  --  0
		                  ����  --  ʧ��
	*/
	virtual ULONG Notify( LP_UDISK_INFO lpUDiskInfo ) = 0;


	/*
		* Parameter(s)  : 
		* Description   : �����ӿ�
		* Return        : �ɹ�  --  0
		                  ����  --  ʧ��
	*/
	virtual ULONG NotifyEx( LP_UDISK_INFO lpUDiskInfo, PVOID pParam1, PVOID pParam2 ) = 0;






	/*
	*
	*	Notify		U�̲���γ�ʱ֪ͨ��	SessionId:�û��ػ�ID
	*								UserName: ��ǰ��¼�û�����
	*								Drive:    U���̷� �� 'F'
	*								Action:   U�̶��� 1:���� 2:�γ�
	*				����ֵ��0 �ɹ�������ʧ��
	*
	*/
// 	virtual ULONG Notify(ULONG SessionId, LPCSTR UserName, CHAR Drive, ULONG Action) = 0;
// 	virtual ULONG Notify(ULONG SessionId, LPCWSTR UserName, CHAR Drive, ULONG Action) = 0;
};



IEdpNotify* WINAPI EdpCreateObject(ULONG ObjectId);
typedef IEdpNotify* (WINAPI *EDP_CREATE_OBJECT)(ULONG ObjectId);

/* ��������

	IEdpNotify * pEdpObject = EdpCreateObject(EDP_NOTIFY_ID);

	// ��������ʱ��ʼ������
	if(pEdpObject)
	{
		if(!pEdpObject->Initialize())
		{
			pEdpObject->Release();
			pEdpObject = NULL;
		}
	}


	UDISK_INFO uDiskInfo;
	memset( &uDiskInfo, 0, LENGTH_UDISK_INFO );

	
	// ��uDiskInfo���ֶθ�ֵ
	// ...
	//

	// ���� U �̲�����߰γ�ʱ����
	if(pEdpObject)
	{
		ULONG ulRet = pEdpObject->Notify( &uDiskInfo );

		// �ж� ulRet ����ֵ�����Ƿ���óɹ�
		// �ɹ�
		if ( 0 == ulRet )
		{
		}
		// ʧ��
		else
		{
		}
	}

	// �������˳�ʱ����
	if(pEdpObject)
	{
		pEdpObject->Terminate();
		pEdpObject->Release();
	}

*/




#endif // __EDP_NOTIFY_H__2014_12_03__