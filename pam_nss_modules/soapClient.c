/* soapClient.c
   Generated by gSOAP 2.7.16 from webservice.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.7.16 2012-06-10 15:20:06 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__oncall(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *loggeduser, char **salutation)
{	struct ns2__oncall soap_tmp_ns2__oncall;
	struct ns2__oncallResponse *soap_tmp_ns2__oncallResponse;
	if (!soap_endpoint) soap_endpoint = "https://server.hostname/webservice.php";
	if (!soap_action) soap_action = "http://schemas.xmlsoap.org/soap/envelope/#Backend#oncall";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns2__oncall.loggeduser = loggeduser;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns2__oncall(soap, &soap_tmp_ns2__oncall);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__oncall(soap, &soap_tmp_ns2__oncall, "ns2:oncall", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__oncall(soap, &soap_tmp_ns2__oncall, "ns2:oncall", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!salutation)
		return soap_closesock(soap);
	*salutation = NULL;
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns2__oncallResponse = soap_get_ns2__oncallResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (salutation && soap_tmp_ns2__oncallResponse->salutation)
		*salutation = *soap_tmp_ns2__oncallResponse->salutation;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */