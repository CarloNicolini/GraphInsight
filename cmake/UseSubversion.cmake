# - Extract information from a subversion repository
# The module defines the following variables:
# SUBVERSION_SVN_EXECUTABLE - path to the subversion command line client
# SUBVERSION_VERSION_SVN - version of the subversion command line client
#
# The module defines the following macros:
# SUBVERSION_REPOSITORY(<DIR>): extract information of a subversion
#                               working copy at location <DIR>
#   It defines the following variables:
#   SUBVERSION_REPO_URL - url of the repository (at location <DIR>)
#   SUBVERSION_REPO_ROOT - root url of the repository
#   SUBVERSION_REPO_REVISION - current revision
#   SUBVERSION_REPO_LAST_CHANGED_AUTHOR - author of last commit
#   SUBVERSION_REPO_LAST_CHANGED_DATE - date of last commit
#   SUBVERSION_REPO_LAST_CHANGED_REV - revision of last commit
#   SUBVERSION_REPO_INFOS - output of command `svn info <DIR>'
#

# Copyright (c) 2006, Tristan Carel
# All rights reserved.
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the University of California, Berkeley nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# $Id:: UseSubversion.cmake 127 2006-10-24 19:28:12Z tristan                  $

SET(SUBVERSION_FOUND FALSE)
SET(SUBVERSION_SVN_FOUND FALSE)

FIND_PROGRAM(SUBVERSION_SVN_EXECUTABLE svn
  DOC "subversion command line client")

IF(SUBVERSION_SVN_EXECUTABLE)
  SET(SUBVERSION_SVN_FOUND TRUE)
  SET(SUBVERSION_FOUND TRUE)

  MACRO(SUBVERSION_REPOSITORY location)
    EXEC_PROGRAM(${SUBVERSION_SVN_EXECUTABLE} ${PROJECT_SOURCE_DIR}
      ARGS --version OUTPUT_VARIABLE SUBVERSION_VERSION_SVN)

    EXECUTE_PROCESS(COMMAND ${SUBVERSION_SVN_EXECUTABLE} info ${location}
      OUTPUT_VARIABLE SUBVERSION_REPO_INFOS
      ERROR_VARIABLE svn_info_error)

    IF(NOT ${svn_info_error})
      MESSAGE(ERROR "
while executing command `svn info ${location}'. Error message:
${svn_info_error}")
    ELSE(NOT ${svn_info_error})

      STRING(REGEX REPLACE "^(.*\n)?svn, version ([.0-9]+).*" "\\2"
	SUBVERSION_VERSION_SVN ${SUBVERSION_VERSION_SVN})
      STRING(REGEX REPLACE "^(.*\n)?URL: ([^\n]+).*"
	"\\2" SUBVERSION_REPO_URL ${SUBVERSION_REPO_INFOS})
      STRING(REGEX REPLACE "^(.*\n)?Revision: ([^\n]+).*"
	"\\2" SUBVERSION_REPO_REVISION ${SUBVERSION_REPO_INFOS})
      STRING(REGEX REPLACE "^(.*\n)?Last Changed Author: ([^\n]+).*"
	"\\2" SUBVERSION_REPO_LAST_CHANGED_AUTHOR ${SUBVERSION_REPO_INFOS})
      STRING(REGEX REPLACE "^(.*\n)?Last Changed Rev: ([^\n]+).*"
	"\\2" SUBVERSION_REPO_LAST_CHANGED_REV ${SUBVERSION_REPO_INFOS})
      STRING(REGEX REPLACE "^(.*\n)?Last Changed Date: ([^\n]+).*"
	"\\2" SUBVERSION_REPO_LAST_CHANGED_DATE ${SUBVERSION_REPO_INFOS})
      MARK_AS_ADVANCED(SUBVERSION_SVN_EXECUTABLE)
    ENDIF(NOT ${svn_info_error})
  ENDMACRO(SUBVERSION_REPOSITORY)

ENDIF(SUBVERSION_SVN_EXECUTABLE)

# UseSubversion.cmake ends here.

