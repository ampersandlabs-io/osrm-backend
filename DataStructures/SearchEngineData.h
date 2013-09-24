/*
    open source routing machine
    Copyright (C) Dennis Luxen, others 2010

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU AFFERO General Public License as published by
the Free Software Foundation; either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
or see http://www.gnu.org/licenses/agpl.txt.
 */

#ifndef SEARCH_ENGINE_DATA_H
#define SEARCH_ENGINE_DATA_H

#include "BinaryHeap.h"
#include "QueryEdge.h"
#include "StaticGraph.h"

#include "../typedefs.h"

#include <boost/thread.hpp>

#include <string>
#include <vector>

struct _HeapData {
    NodeID parent;
    _HeapData( NodeID p ) : parent(p) { }
};

// typedef StaticGraph<QueryEdge::EdgeData> QueryGraph;

struct SearchEngineData {
    typedef BinaryHeap< NodeID, NodeID, int, _HeapData, UnorderedMapStorage<NodeID, int> > QueryHeap;
    typedef boost::thread_specific_ptr<QueryHeap> SearchEngineHeapPtr;

    static SearchEngineHeapPtr forwardHeap;
    static SearchEngineHeapPtr backwardHeap;
    static SearchEngineHeapPtr forwardHeap2;
    static SearchEngineHeapPtr backwardHeap2;
    static SearchEngineHeapPtr forwardHeap3;
    static SearchEngineHeapPtr backwardHeap3;

    void InitializeOrClearFirstThreadLocalStorage(const unsigned number_of_nodes);

    void InitializeOrClearSecondThreadLocalStorage(const unsigned number_of_nodes);

    void InitializeOrClearThirdThreadLocalStorage(const unsigned number_of_nodes);
};

#endif // SEARCH_ENGINE_DATA_H
