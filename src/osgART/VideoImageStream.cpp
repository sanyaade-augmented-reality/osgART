/* -*-c++-*- 
 * 
 * osgART - Augmented Reality ToolKit for OpenSceneGraph
 * 
 * Copyright (C) 2005-2009 Human Interface Technology Laboratory New Zealand
 * Copyright (C) 2010-2013 Raphael Grasset, Julian Looser, Hartmut Seichter
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the osgart.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/

#include "osgART/VideoImageStream"

#include <osg/Notify>

/**
 * \file osgART\VideoImageStream.cpp
 * \author Hartmut Seichter <hartmut@technotecture.com>
 * \brief implements a video sources using osg::ImageStream
 */
namespace osgART 
{

	VideoImageStream::VideoImageStream() : osg::ImageStream()
	{
	}

	VideoImageStream::VideoImageStream(const VideoImageStream& video,
		const osg::CopyOp& copyop) : 
		osg::ImageStream(video,copyop)
	{
	}

	/* virtual */
	void
	VideoImageStream::start() 
	{
		this->play();
	}
	
	/*virtual*/
	void
	VideoImageStream::stop()
	{
		this->pause();
	}
	
	/*virtual*/
	bool
	VideoImageStream::open() 
	{
		return false;
	}

	/*virtual*/
	void
	VideoImageStream::close(bool waitForThread/* = true*/) 
	{
		this->quit(waitForThread);
	}

	VideoImageStream::~VideoImageStream()
	{
		this->close(false);
	}
	
}
