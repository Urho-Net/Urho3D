// Copyright (c) 2020 Eli Aloni (a.k.a  elix22)
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


using System;
using Urho.Physics;
using Urho;
using System.Collections.Generic;

namespace Urho
{

    enum AsyncLoadType
    {
        e_Xml,
        e_Json,
        e_Binary
    }

    enum AsyncLoadStatus
    {
        e_Idle,
        e_Loading,
        e_Loaded
    }
    class AsyncNode
    {
        public string path;
        public AsyncLoadType loadType;
        public AsyncLoadStatus loatStatus;

        public AsyncNode()
        {
            path = "";
            loadType = AsyncLoadType.e_Binary;
            loatStatus = AsyncLoadStatus.e_Idle;
        }
    }

    public class AsyncLoader : IDisposable
    {
        private Scene asyncNodeLoader = null;

        private List<AsyncNode> asyncNodeToLoadList = new List<AsyncNode>();
        private Dictionary<Scene, string> asyncResourceLoaders = new Dictionary<Scene, string>();

        private object __lockObj = new object();
        private bool disposedValue;

        public event Action<AsyncLoadProgressEventArgs, string> AsyncNodeLoadProgress;
        public event Action<AsyncLoadFinishedEventArgs, string> AsyncNodeLoadFinished;

        public event Action<AsyncLoadProgressEventArgs, string> AsyncResourceLoadProgress;
        public event Action<AsyncLoadFinishedEventArgs, string> AsyncResourceLoadFinished;


        //
        // Summary:
        //     Return maximum milliseconds per frame to spend on async loading. Or Set maximum
        //     milliseconds per frame to spend on async scene loading.
        public int AsyncLoadingMs
        {
            get
            {
                if (asyncNodeLoader != null)
                {
                    return asyncNodeLoader.AsyncLoadingMs;
                }
                else
                    return 0;
            }

            set
            {
                if (asyncNodeLoader != null)
                {
                    asyncNodeLoader.AsyncLoadingMs = value;
                }
            }
        }

        //
        // Summary:
        //     Return Maximum milliseconds interval between qonsequtive asynLoad calls. Or Set
        //     inerval milliseconds between consequtive loads.
        public int AsyncIntervalMs
        {
            get
            {
                if (asyncNodeLoader != null)
                {
                    return asyncNodeLoader.AsyncIntervalMs;
                }
                else
                    return 0;
            }

            set
            {
                if (asyncNodeLoader != null)
                {
                    asyncNodeLoader.AsyncIntervalMs = value;
                }
            }
        }

        public AsyncLoader()
        {
            asyncNodeLoader = new Scene();
            asyncNodeLoader.Temporary = true;
            asyncNodeLoader.CreateComponent<Octree>();
            asyncNodeLoader.CreateComponent<PhysicsWorld>();
            asyncNodeLoader.CreateComponent<DebugRenderer>();
            asyncNodeLoader.AsyncLoadProgress += HandleLoadNodeProgress;
            asyncNodeLoader.AsyncLoadFinished += HandleNodeLoaded;

            if (Application.HasCurrent && !Application.isExiting)
                Application.Current.Update += OnUpdate;
        }

        private void OnUpdate(UpdateEventArgs obj)
        {
            lock (__lockObj)
            {
                if (asyncNodeToLoadList.Count > 0)
                {
                    AsyncNode asyncNode = asyncNodeToLoadList[0];
                    if (asyncNode.loatStatus == AsyncLoadStatus.e_Idle)
                    {
                        asyncNode.loatStatus = AsyncLoadStatus.e_Loading;

                        switch (asyncNode.loadType)
                        {
                            case AsyncLoadType.e_Xml:
                                {
                                    if (asyncNodeLoader.LoadAsyncNodeXml(asyncNode.path) == false)
                                    {
                                        asyncNodeToLoadList.Remove(asyncNode);
                                    }
                                }
                                break;

                            case AsyncLoadType.e_Json:
                                {
                                    if (asyncNodeLoader.LoadAsyncNodeJson(asyncNode.path) == false)
                                    {
                                        asyncNodeToLoadList.Remove(asyncNode);
                                    }
                                }
                                break;

                            case AsyncLoadType.e_Binary:
                                {
                                    if (asyncNodeLoader.LoadAsyncNode(asyncNode.path) == false)
                                    {
                                        asyncNodeToLoadList.Remove(asyncNode);
                                    }
                                }
                                break;
                        }
                    }
                    else if (asyncNode.loatStatus == AsyncLoadStatus.e_Loaded)
                    {
                        asyncNodeToLoadList.Remove(asyncNode);
                    }
                }
            }
        }

        private void HandleResourceLoaded(AsyncLoadFinishedEventArgs args)
        {
            if (asyncResourceLoaders.TryGetValue(args.Scene, out string path))
            {
                AsyncResourceLoadFinished?.Invoke(args, path);
                args.Scene.AsyncLoadProgress -= HandleLoadResourceProgress;
                args.Scene.AsyncLoadFinished -= HandleResourceLoaded;
                asyncResourceLoaders.Remove(args.Scene);
                args.Scene.Remove();
            }
        }

        private void HandleLoadResourceProgress(AsyncLoadProgressEventArgs args)
        {
            if (asyncResourceLoaders.TryGetValue(args.Scene, out string path))
            {
                AsyncResourceLoadProgress?.Invoke(args, path);
            }
        }

        public bool LoadAsynResourceXml(string filePath)
        {
            var cache = Application.Current.ResourceCache;
            bool status = false;
            using (var file = cache.GetFile(filePath))
            {
                if (file != null && file.IsOpen())
                {

                    Scene asyncResourceLoader = new Scene();
                    asyncResourceLoader.Temporary = true;
                    asyncResourceLoader.AsyncLoadProgress += HandleLoadResourceProgress;
                    asyncResourceLoader.AsyncLoadFinished += HandleResourceLoaded;

                    asyncResourceLoaders.Add(asyncResourceLoader, filePath);
                    status = asyncResourceLoader.LoadAsyncXml(file, LoadMode.ResourcesOnly);

                    if (status == false)
                    {
                        asyncResourceLoaders.Remove(asyncResourceLoader);
                    }



                }
            }

            return status;
        }

        public bool LoadAsynResourceJson(string filePath)
        {
            var cache = Application.Current.ResourceCache;
            bool status = false;
            using (var file = cache.GetFile(filePath))
            {
                if (file != null && file.IsOpen())
                {

                    Scene asyncResourceLoader = new Scene();
                    asyncResourceLoader.Temporary = true;
                    asyncResourceLoader.AsyncLoadProgress += HandleLoadResourceProgress;
                    asyncResourceLoader.AsyncLoadFinished += HandleResourceLoaded;

                    asyncResourceLoaders.Add(asyncResourceLoader, filePath);
                    status = asyncResourceLoader.LoadAsyncJson(file, LoadMode.ResourcesOnly);

                    if (status == false)
                    {
                        asyncResourceLoaders.Remove(asyncResourceLoader);
                    }
                }
            }

            return status;
        }

        public bool LoadAsynResource(string filePath)
        {
            var cache = Application.Current.ResourceCache;
            bool status = false;
            using (var file = cache.GetFile(filePath))
            {
                if (file != null && file.IsOpen())
                {

                    Scene asyncResourceLoader = new Scene();
                    asyncResourceLoader.Temporary = true;
                    asyncResourceLoader.AsyncLoadProgress += HandleLoadResourceProgress;
                    asyncResourceLoader.AsyncLoadFinished += HandleResourceLoaded;

                    asyncResourceLoaders.Add(asyncResourceLoader, filePath);
                    status = asyncResourceLoader.LoadAsync(file, LoadMode.ResourcesOnly);

                    if (status == false)
                    {
                        asyncResourceLoaders.Remove(asyncResourceLoader);
                    }
                }
            }

            return status;
        }



        public void LoadAsyncNodeXml(string nodePath)
        {
            lock (__lockObj)
            {
                AsyncNode asyncNode = new AsyncNode();
                asyncNode.path = nodePath;
                asyncNode.loadType = AsyncLoadType.e_Xml;
                asyncNodeToLoadList.Add(asyncNode);
            }
        }

        public void LoadAsyncNodeJson(string nodePath)
        {
            lock (__lockObj)
            {
                AsyncNode asyncNode = new AsyncNode();
                asyncNode.path = nodePath;
                asyncNode.loadType = AsyncLoadType.e_Json;
                asyncNodeToLoadList.Add(asyncNode);
            }
        }

        public void LoadAsyncNode(string nodePath)
        {
            lock (__lockObj)
            {
                AsyncNode asyncNode = new AsyncNode();
                asyncNode.path = nodePath;
                asyncNode.loadType = AsyncLoadType.e_Binary;
                asyncNodeToLoadList.Add(asyncNode);
            }
        }

        private void HandleNodeLoaded(AsyncLoadFinishedEventArgs args)
        {
            if (args.Node != null)
            {
                lock (__lockObj)
                {
                    if (asyncNodeToLoadList.Count > 0)
                    {
                        AsyncNode asyncNode = asyncNodeToLoadList[0];
                        args.Node.AddRef();
                        AsyncNodeLoadFinished?.Invoke(args,asyncNode.path);
                        asyncNodeLoader.RemoveChild(args.Node);
                        asyncNode.loatStatus = AsyncLoadStatus.e_Loaded;
                    }
                }
            }
        }

        private void HandleLoadNodeProgress(AsyncLoadProgressEventArgs args)
        {
            lock (__lockObj)
            {
                if (asyncNodeToLoadList.Count > 0)
                {
                    AsyncNode asyncNode = asyncNodeToLoadList[0];
                    AsyncNodeLoadProgress?.Invoke(args, asyncNode.path);
                }
            }
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects)
                }

                if (!Application.isExiting && Application.HasCurrent)
                {
                    asyncNodeLoader.AsyncLoadProgress -= HandleLoadNodeProgress;
                    asyncNodeLoader.AsyncLoadFinished -= HandleNodeLoaded;
                    asyncNodeLoader.Remove();
                    asyncNodeLoader = null;

                    Application.Current.Update -= OnUpdate;

                    foreach (var asyncResourceLoader in asyncResourceLoaders)
                    {
                        asyncResourceLoader.Key.AsyncLoadProgress -= HandleLoadResourceProgress;
                        asyncResourceLoader.Key.AsyncLoadFinished -= HandleResourceLoaded;
                        asyncResourceLoader.Key.Remove();
                    }

                    asyncResourceLoaders.Clear();
                }
                disposedValue = true;
            }
        }

        ~AsyncLoader()
        {
            Dispose(disposing: false);
        }

        public void Dispose()
        {
            Dispose(disposing: true);
            GC.SuppressFinalize(this);
        }
    }

}