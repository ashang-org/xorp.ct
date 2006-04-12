#!/usr/bin/env python

# Copyright (c) 2001-2006 International Computer Science Institute
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software")
# to deal in the Software without restriction, subject to the conditions
# listed in the XORP LICENSE file. These conditions include: you must
# preserve this copyright notice, and you cannot mention the copyright
# holders in advertising related to the Software without their permission.
# The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
# notice is a summary of the XORP LICENSE file; the license in that file is
# legally binding.

# $XORP: xorp/tests/test_xorpsh.py,v 1.2 2006/04/07 20:16:26 atanu Exp $

import popen2

def xorpsh(builddir, command, templates = '../templates'):
    """
    Send commands via the xorpsh
    """

    xorpsh_path = builddir + "rtrmgr/xorpsh -t %s" % templates

    process = popen2.Popen4(xorpsh_path)
    process.tochild.write(command)
    process.tochild.close()

    # XXX - This is not really a satisfactory way of determining if an
    # error has occurred
    error_responses = ["ERROR", "unknown command", "syntax error",
                       "Commit Failed"]

    while 1:
        line = process.fromchild.readline()
        if not line:
            break
        for i in error_responses:
            if line.startswith(i):
                raise Exception, line
        print line,
    status = process.wait()

    if 0 == status:
        return True
    else:
        return False