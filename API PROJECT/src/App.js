import React from 'react';

import Home from './components/Home';
import MyBooks from './components/MyBooks';
import Layout from './components/Layout';
import Login from './components/Login';
import Signup from './components/Signup';
import { Outlet } from 'react-router-dom';

import { BrowserRouter, Routes, Route } from 'react-router-dom';

function App() {
  return (
    <>
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<Layout />} />
            <Route index element={<Outlet />} />
            <Route path='/home' element={<Home />} />
            <Route path='/login' element={<Login />} />
            <Route path='/signup' element={<Signup />} />
            <Route path='/layout' element={<Layout />} />
            <Route path='/mybooks' element={<MyBooks />} />
        </Routes>
      </BrowserRouter>
    </>
  )
}

export default App
