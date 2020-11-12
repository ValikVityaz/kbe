#pragma once

#include "scgstreamwriter.h"

//! TODO: add error messages

class SCgObject;
class SCgNode;

class SCgFileWriter
{
public:
    SCgFileWriter();
    virtual ~SCgFileWriter();

    /*! Saves gwf format to file.
      @param file_name Name of file.
      @param input scg-editor scene.

      @return If file saved, then return true, else - false.
      */
    bool save(QString file_name, QObject *input);

private:

    SCgStreamWriter stream;
};


